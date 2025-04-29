# pragma execution_character_set("utf-8")

#include "HansInput.h"

HansInput::HansInput(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

HansInput::~HansInput()
{
	releaseUp();
}


void HansInput::inputInit(HWND hwnd)  //初始化接口等，需要传入一个ui组件的指针，来指定墨水收集和识别的区域
{
	if (hwnd == nullptr) //没有指定墨迹识别的区域
		return;

	p_IInkCollector = nullptr; //墨迹收集和管理
	p_IInkDisp = nullptr;  //墨迹显示
	p_IInkRecognizerContext = nullptr;  //墨迹识别


	HRESULT hr;  //表示函数调用成功或者失败的状态

	hr = CoInitialize(nullptr);  //初始化COM接口  LPVOID == void*
	if (FAILED(hr))
	{
		qDebug() << "Failed to CoInitialize()";
		return;
	}


	//使用默认识别器创建一个识别上下文
	//这个上下文会被所有识别对象使用
	//请求 COM 框架创建一个 IInkRecognizerContext 接口的实例，并返回该接口的指针
	hr = CoCreateInstance(
		CLSID_InkRecognizerContext,     //唯一标识一个 COM 组件的类
		NULL,                           //指向 IUnknown 接口的指针  不需要聚合
		CLSCTX_INPROC_SERVER,           //对象将在进程内服务器中创建
		IID_IInkRecognizerContext,      //唯一标识一个 COM 接口
		(void**)&p_IInkRecognizerContext //返回创建好的实例的指针
	);

	if (FAILED(hr))
	{
		qDebug() << "Failed to CoCreateInstance(CLSID_InkRecognizerContext)";
		return;
	}


	//创建一个墨迹收集的对象
	hr = CoCreateInstance(
		CLSID_InkCollector,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IInkCollector,
		(void**) &p_IInkCollector
	);

	if (FAILED(hr))
	{
		qDebug() << "Failed to CoCreateInstance(CLSID_InkCollector)";
		return;
	}


	//获取墨迹对象指针
	hr = p_IInkCollector->get_Ink(&p_IInkDisp);
	if (FAILED(hr))
	{
		qDebug() << "Failed to get_Ink(&p_IInkDisp)";
		return;
	}


	//将墨迹对象关联一个组件 hwnd
	hr = p_IInkCollector->put_hWnd((long)hwnd);
	if (FAILED(hr))
	{
		qDebug() << "Failed to put_hWnd((long)hwnd)";
		return;
	}


	//设置颜色
	//IInkDrawingAttributes* p;
	//if (SUCCEEDED(p_IInkCollector->get_DefaultDrawingAttributes(&p)))  //获取墨迹收集器的默认绘图属性
	//{
	//	//p->put_Color(RGB(0, 0, 255));  //颜色置为蓝色
	//}
	//else
	//{
	//	qDebug() << "Failed to set the color";
	//}

	//打开墨迹输入开关
	hr = p_IInkCollector->put_Enabled(VARIANT_TRUE);
	if (FAILED(hr))
	{
		qDebug() << "Failed to put_Enabled(VARIANT_TRUE)";
		return;
	}
	
	


	//如有需要后期可以设置IInkRecgnizerGuide

}


void HansInput::RecogData(InPutResS& Res) //墨迹识别
{
	//将系统光标更改为沙漏
	//HCURSOR hCursor = ::SetCursor(::LoadCursor(NULL, IDC_WAIT));

	//识别之前先将上一次识别的结果清空
	if (!Res.empty())
	{
		Res.clear();
	}

	//获取指向墨迹收集器的指针，这个收集器是整个墨迹的快照
	IInkStrokes* p_IInkStrokes = nullptr;
	HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //可以通过p_IInkStrokes访问和操作墨迹笔划集合。
	if (SUCCEEDED(hr))
	{
		//将笔触收集器传递给识别器
		hr = p_IInkRecognizerContext->putref_Strokes(p_IInkStrokes);  //设置识别上下文中将要进行识别的墨迹笔划集合
		if (SUCCEEDED(hr))
		{
			//识别
			IInkRecognitionResult* p_IInkRecoResult = nullptr;
			InkRecognitionStatus RecognitionStatus = IRS_NoError;  //COM 接口，代表墨迹识别的状态

			hr = p_IInkRecognizerContext->Recognize(&RecognitionStatus, &p_IInkRecoResult);  //识别器会返回结果 在形参列表里面引用返回

			if (SUCCEEDED(hr) && (p_IInkRecoResult != nullptr))  //识别成功并且有结果
			{
				IInkRecognitionAlternates* p_IInkRecognitionAlternates;    //-s

				hr = p_IInkRecoResult->AlternatesFromSelection(
					0,                                 //选择的起始索引  这里 0 表示从第一个候选词开始检索          in
					-1,                                //选择的结束索引  -1 通常用于指示直到列表末尾的最后一个候选词  in
					5,                                 //要检索的候选词的最大数量  即返回具有 5个候选词的结果        in
					&p_IInkRecognitionAlternates       //指向候选词集合                                         out
				);

				long lCount = 0;
				if (SUCCEEDED(hr) && SUCCEEDED(p_IInkRecognitionAlternates->get_Count(&lCount)))
				{
					//获取所有识别结果
					IInkRecognitionAlternate* p_IInkRecognitionAlternate = nullptr;  

					for (LONG iTem = 0; (iTem < lCount) && (iTem < 5); iTem++)
					{
						if (SUCCEEDED(p_IInkRecognitionAlternates->Item(iTem, &p_IInkRecognitionAlternate)))
						{
							BSTR bstr = nullptr;

							if (SUCCEEDED(p_IInkRecognitionAlternate->get_String(&bstr)))
							{
								InputRes temp = { 0 };
								QString str = QString::fromWCharArray(bstr);

								qDebug() << str.toUtf8().data();

								strcpy_s(temp.res, str.toUtf8().data());
								Res.push_back(temp);
							}

							p_IInkRecognitionAlternate->Release();
						}
					}

				}
			}

			//重置识别器的内容
			p_IInkRecognizerContext->putref_Strokes(nullptr);

		}

		p_IInkStrokes->Release(); 

	}


}

void HansInput::releaseUp()  //释放与墨迹输入相关的接口资源，清理COM
{
	if (p_IInkRecognizerContext != nullptr)
	{
		p_IInkRecognizerContext->Release();
		p_IInkRecognizerContext = nullptr;
	}

	if (p_IInkDisp != nullptr)
	{
		p_IInkDisp->Release();
		p_IInkDisp = nullptr;
	}

	if (p_IInkCollector != nullptr)
	{
		p_IInkCollector->Release();
		p_IInkCollector = nullptr;
	}

	CoUninitialize();
}

void HansInput::clear() //清除所有笔划
{
	p_IInkDisp->DeleteStrokes(nullptr);
	qDebug() << "Delete Strokes";
}


//笔划集合里面确实是删除了一笔，但是没有同步回馈到界面，而且删除一笔之后，也应该再次识别的，及时回馈结果
void HansInput::clearNew() //清除最新的一笔，回退一笔
{
	//获取墨迹笔划集合
	IInkStrokes* p_IInkStrokes = nullptr;
	HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //out

	if (SUCCEEDED(hr) && p_IInkStrokes != nullptr) //成功获取笔划集合，并且笔划集合不为空  才能够开始删除操作
	{
		//获取笔划数量
		long count = 0;
		p_IInkStrokes->get_Count(&count);

		if (count > 0)
		{
			IInkStrokeDisp* p_lastStroke = nullptr;
			hr = p_IInkStrokes->Item(count - 1, &p_lastStroke);  //获取笔划集合当中，指向最后一笔的指针

			if (SUCCEEDED(hr) && p_lastStroke != nullptr)
			{
				hr = p_IInkDisp->DeleteStroke(p_lastStroke);
				qDebug() << "SUCCEEDED to DeleteStroke(p_lastStroke)";

				if (FAILED(hr))
				{
					qDebug() << "Failed to DeleteStroke(p_lastStroke)";
					return;
				}

				//删除笔划集合之后，要保证能够更新到UI
				LONG_PTR curHWND = 0;
				hr = p_IInkCollector->get_hWnd(&curHWND);

				if (SUCCEEDED(hr))
				{
					HWND hwnd = reinterpret_cast<HWND>(curHWND);
					hr = InvalidateRect(hwnd, NULL, TRUE);

					if (FAILED(hr))
					{
						qDebug() << "InvalidateRect(hwnd, NULL, TRUE)";
						return;
					}

				}

				//重新识别信号
				emit deleteLast();
				


			}
			else
			{
				qDebug() << "Failed to Item(count - 1, &p_lastStroke)";
				return;
			}
		}
		else
		{
			return; //笔划集合为空，直接返回，什么也不做
		}
	}
	else
	{
		qDebug() << "Failed to get_Strokes(&p_IInkStrokes)";
		return;
	}


}

 