# 手写输入法识别测试

下面将详细测试基于Qt的窗口应用程序——手写输入法。

## 1. 界面设计以及说明

本程序是基于Qt + windows API 开发的，需要Qt以及Windows的环境。

### 1.1 主界面以及说明
运行程序之后，可以看到：
![](https://oss-liuchengtu.hudunsoft.com/userimg/8a/8a1d55252be2dd53971826da412154f7.png)

==之后加入联想词候选栏后可以看到：==
单字识别模式：
![](https://oss-liuchengtu.hudunsoft.com/userimg/2a/2ab055b78a59b7679a3adffe1ae9cc8d.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/98/98ddd94084095999019cffbabd4fb1bb.png)


多字识别模式：
![](https://oss-liuchengtu.hudunsoft.com/userimg/06/064deed0f991422f4527bb26f18d19a9.png)



下面是每一个界面组件功能的解释：
![](https://oss-liuchengtu.hudunsoft.com/userimg/cc/cc90f0d6d4350f97764fb2cef5b89156.png)

从上图中可以看到，按钮`单字手写`变为蓝底，显示高亮，表明当前的识别模式是“单字手写识别”。如果想要使用多字识别的功能，直接点击按钮`多字手写`，就可以实现模式的切换。如下是多字识别模式：
![](https://oss-liuchengtu.hudunsoft.com/userimg/a0/a0089814a1f1c86b5d55e9ea774d86ba.png)
布局和单字识别差不多，但是手写区域拉长之后，就能给用户更好的体验。

初始界面默认为支持汉字识别，想要更快速的输入符号，可以点击符号按钮来查找符号。
![](https://oss-liuchengtu.hudunsoft.com/userimg/45/458588b07d74aed99816c93d041e8526.png)


==由于文档是分多次书写，所以前后会有 "有无联想候选栏" 的差异，对于识别功能上的测试是一样的，只是后来多了一个联网实现候选栏的功能。==


### 1.2 子窗口以及说明

**设置**子窗口
点击设置，按钮会变成蓝色，按钮的提示文本会变成“关闭窗口”，并弹出窗口，如下：
![](https://oss-liuchengtu.hudunsoft.com/userimg/00/001506304f832806868d87ae74e4f955.png)

再次点击按钮，按钮会再次变回白色并关闭窗口。
从运行结果可以看到，设置界面主要有四种功能：
1. 设置墨迹颜色，对中间的手写区域有效。
2. 设置墨迹粗细，对中间的手写区域有效。
3. 设置候选框内的字号，对右侧的候选框按钮有效。
4. 恢复默认设置。

**特殊符号栏** 子窗口

运行结果如下：
![](https://oss-liuchengtu.hudunsoft.com/userimg/2e/2e1e302f8c0349ab230d5fbf0e7ad2d4.png)

同理，数字符号和字母符号也是一样的：
![](https://oss-liuchengtu.hudunsoft.com/userimg/58/588d4f76107b2c52f1f71ab7f921fb3b.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/36/3699e9ce95884f71fb35e2cf28937cc7.png)


## 2. 单字手写识别功能

![](https://oss-liuchengtu.hudunsoft.com/userimg/b2/b2d51a5b9701be91d1c26210401a7e33.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/ee/eeea8c85bf5b81b2d670d62d24366c33.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/10/1090394a65abf1084616922edb3af10a.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/ea/ea52527e11597c61e889467bff92f8ea.png)


## 3. 多字手写识别功能

![](https://oss-liuchengtu.hudunsoft.com/userimg/fd/fda4b5d0a6b005a537f2df8177076a68.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/6a/6a976cd91f3ed0fbb932d633d7b0f340.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/af/af7f538f5f713c9cf1e3a65242e27764.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/6a/6afa4b9fe719d033edb26e3d7051cbb7.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/6c/6c1121004c26417cb4bed4e5aabb5b85.png)


## 4. 重写功能测试

多字识别模式和单字识别模式的重写功能一样，以单字识别为例，进行测试：
![](https://oss-liuchengtu.hudunsoft.com/userimg/30/308da6feb2993be69760e39f9340f9d7.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/ef/ef817ac0a90d2758286640d57e4d2f73.png)


## 5. 退一笔功能功能测试

这是最开始的字：
![](https://oss-liuchengtu.hudunsoft.com/userimg/42/426acf1af5bfa2e3f5632dcb680ff112.png)
退一笔之后:
![](https://oss-liuchengtu.hudunsoft.com/userimg/91/9186f6ed8a3325f80241aa33c9aa0cc9.png)
再退一笔：
![](https://oss-liuchengtu.hudunsoft.com/userimg/9f/9f6e46c65ba7801ccbef813fc9623bae.png)
后面以此类推：
![](https://oss-liuchengtu.hudunsoft.com/userimg/34/3429d7cdff57e8e3fbe2d7b73181bed0.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/55/55e9425750db579abbf2b0c7c1a32656.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/32/32a798fdcb073bf90167fb000829d3e8.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/7e/7ec4eb43ef9d7a0e96a430de07091c14.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/f3/f3a53ccb0fd9e04ac83319411937db23.png)

下面是部分调试信息：
![](https://oss-liuchengtu.hudunsoft.com/userimg/31/3144ad6e5889e721a49b8e0934a70085.png)


## 6. 设置功能

不设置墨迹样式和候选字字号的时候，会有一个默认样式，无论怎么改，都可以从设置界面的“恢复默认设置”按钮改回来。
默认样式展示如下：
![](https://oss-liuchengtu.hudunsoft.com/userimg/72/72d291eb91bf0b9564b3dd256280ef3a.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/2d/2d43d6f9167b65c76645c9193b22c302.png)


下面随机搭配几组样式演示一下：

**1**

墨迹颜色：红
墨迹粗细：5
候选字号：6

![](https://oss-liuchengtu.hudunsoft.com/userimg/4d/4d7e634163f3d12281e69a3a5db99787.png)
设置是全局的，多字识别和单字识别的模式的墨迹样式都会变化：
![](https://oss-liuchengtu.hudunsoft.com/userimg/85/853c8d50f3679e18a1f1b1e582fd8ed8.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/e1/e1fb92bd17ebcbd6b1faef7041fae179.png)


**2**
墨迹颜色：蓝
墨迹粗细：6
候选字号：4

![](https://oss-liuchengtu.hudunsoft.com/userimg/f3/f3b7ac4fd737a3a6c5140e4105d9777e.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/87/879d840187d52dee4d998b7f0107cd88.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/a7/a7f939ad5c3c5cea8e56f3b2e29a8e32.png)


**3**
墨迹颜色：紫
墨迹粗细：2
候选字号：3

![](https://oss-liuchengtu.hudunsoft.com/userimg/11/11c333b032345684c972b1b225cda4d4.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/be/becbf81438286726e971d84b83643efc.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/9b/9b6ad834b570c229d67a6a1f32ea7c9c.png)

再次恢复默认设置：

![](https://oss-liuchengtu.hudunsoft.com/userimg/97/97fab5c56dfb614d5f23d7cf95fc9911.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/c9/c9023784121de2323b5a2b0466678fef.png)

(~~甚至可以换不同的颜色，但是不建议这样做，因为会出现显示不正常的问题，就是墨迹集合里面是保存了墨迹的，但是又是不会刷新在手写区域里面。要想全部显示出来，需要点击退一笔操作，因为这个操作会刷新手写区域，强制显示笔迹。~~)

后续更新，上述bug已经被修复，不存在墨迹隐形的情况。
可以在书写的过程当中换颜色和墨迹的粗细以及字体的大小

![](https://oss-liuchengtu.hudunsoft.com/userimg/6f/6fa887f44d8d189e488e7fe01ac7e17a.png)


## 中英文混合输入

![](https://oss-liuchengtu.hudunsoft.com/userimg/d6/d696c540be2b6b6c4bad2f0231a336a8.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/e4/e4b5a1045d6157c7afa1ed5d1c23331e.png)


## 特殊符号识别
![](https://oss-liuchengtu.hudunsoft.com/userimg/fe/fe9b48bfeccf3c0307a46e64ab6e694c.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/49/49c00c5440bc5fbe69e6cf616550e518.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/3a/3aacc87b1ea8a1ebd342924c9a09cee4.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/fc/fc3b97fcb920297b37a048d2e0cfd546.png)




2024.11.27更
tips: 关于叠加识别和联想字的扩展功能，目前还没有时间做。快期末考试了，我先一边复习一边想一下怎么设计这两个扩展模块。
目前对于联想字的想法是使用一个字典树，字典树将常见的字词短句组合起来构成一颗树，然后根据识别的结果，在树上匹配字词。目前只是有这个想法，但是对于常用的字词句去哪里整合下载资源，我还不知道去哪里找呢，如果实在不行，就自己整合一下。其实这样想，用户个性化输入也可以使用这样的方式，每次用户输入的文本都可以看成一个常用字词的组合，然后加到树里面去构建。


2024.12.9更 
期末考试基本结束了，正好老师最后一次课讲了怎么联网调用API，所以我就想，关键字的查询确实可以联网调用API来实现。


## 联想词功能

由于调用的是`https://sug.so.360.cn/suggest` 浏览器搜索的联想词API，所以搜索结果会更加偏向于时事方面。也就是说，当下什么是社会热点，什么就更容易成为联想词。

单字识别下的联想词查询：
![](https://oss-liuchengtu.hudunsoft.com/userimg/7c/7cb88b1efd8b3a75fff717a8377c0611.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/ec/ece0f8f57cb5545ef8d8ad3c6695a00a.png)

多字识别下的联想词查询：
![](https://oss-liuchengtu.hudunsoft.com/userimg/40/404778f422569de92c2da2528c923d60.png)


退一笔后的联想词更新：
刚开始输入“早：
![](https://oss-liuchengtu.hudunsoft.com/userimg/dc/dc4ebbc2c1daf31845756edbe22085a0.png)
退一笔之后：
![](https://oss-liuchengtu.hudunsoft.com/userimg/2e/2ef0d62d1e96bcc1c10dc15483409c08.png)
以此类推：
![](https://oss-liuchengtu.hudunsoft.com/userimg/86/86f5f37694fc33fc56b7d175b6aed1ef.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/04/048330535b451db5f982fc002db8ea6c.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/1d/1da564697a5d300846d934eb35da7a2f.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/bb/bbcaeb1edc71528d3501e273c2b42ea7.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/7e/7eb280f43d1ba682f599b5e5d69962cd.png)

多字识别也是一样的。


重写测试：
![](https://oss-liuchengtu.hudunsoft.com/userimg/7c/7c1fc543391b87488777ebd4dcc2e74e.png)
点击重写之后，会做三件事情：
1. 清空所有候选字按钮的文本
2. 清空手写区域
3. 清空联想词查询结果


## 关于一些bug

~~目前发现的bug主要是，如果写字写一半，再去点开设置或者符号表的话，会出现部分墨迹隐形的情况。具体如下：
点开某个符号表窗口：~~
![](https://oss-liuchengtu.hudunsoft.com/userimg/ff/ff91653e6d9aa3790023077140da82f2.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/8b/8b782e68b2e4d00a25530a1f24dd372a.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/89/892d8dd412263fdc1e89dec08efca9da.png)

~~点开设置窗口：~~
![](https://oss-liuchengtu.hudunsoft.com/userimg/db/db106ebb20c2f41048c2507cb6d2870e.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/96/9616afb2536da2f6b56eb109729cfff4.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/c4/c4f8b81c1864b34923ca91e436097275.png)

~~这种情况在点击退一笔之后就会复原。~~


==上述bug已经被修复。==



## 打包成exe文件之后在不同的机器下测试

找了几个好朋友让他们做了测试，贴上反馈图片：

1. 朋友一号 反馈的问题很及时，并且及时做了修复，目前已经不存在这个bug.
![](https://oss-liuchengtu.hudunsoft.com/userimg/c9/c9edcf543dcbe3cc7896eb774f8fdaea.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/42/42b65ec2e44b333371484ca85cc36c83.png)

修复之后朋友的反馈：
![](https://oss-liuchengtu.hudunsoft.com/userimg/b6/b6542e144cc3be32f1dbbb211c7aa2cf.png)



2. 朋友二号
![](https://oss-liuchengtu.hudunsoft.com/userimg/7d/7d1b0e541917c9d8b07bccd2551aa390.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/12/122c064ac5a73172f7db2c8985ed8d5b.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/fc/fcb0acffd08d961cd27e9093c597e1f3.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/42/42b941f735cc66ec7c65cf4d7b765c6b.png)

3. 朋友三号

![](https://oss-liuchengtu.hudunsoft.com/userimg/78/78b5d538a4999c69b00912c7a931df78.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/c4/c4c3cbd568e19d237b3fb28403047034.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/95/95dab65f9c52c06666b8ea9aac2d0096.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/06/0683f79d3de07150b63b1b8882c86319.png)



### 发送邮件之后，自己从网络上下载zip，解压然后测试
![](https://oss-liuchengtu.hudunsoft.com/userimg/31/311044d93f999a8c962a260e9ce723c6.png)

能够正常运行。














# 基于Qt的手写输入法开发思路

**前言**：

我的项目从UI到功能设计都是敲代码敲出来的，那为什么不用设计师去设计界面呢？

主要是因为我开始写的时间比较早吧，第一次Qt课结束的时候，我就开始自学Qt里面的基础知识了。我找的那本参考书，里面的例子都是代码敲出来的，关于UI设计的部分还没来得及学，但是我想也快期末考试了，边学边写边找资料吧，免得最后事情都堆在一起，然后就开始敲代码去构建UI界面了。

所以，可能代码和思路都比较幼稚，我也不知道专业的UI会怎么去设计，我只是有一个大概的思路，然后一边做一边思考，整个过程下来，我还是学到了很多也收获了很多的。

关于设计师的使用，之后也会专门去系统学一学的。

==这个文档是分了好几次写的，前后会有 "有无联想词候选栏" 的区别。但是主体功能没有大的变化，前后大部分改动只是为了能够兼容联想词功能。== 所以之前思想和方法都是一样的。后面几次改文档的时候就不做赘述了。



#  整个项目框架

总体分为三个部分：
1. UI界面的构建
2. 识别算法
3. 联网实现联想词查询

最开始，我拿到这个项目是非常懵圈的，识别算法应该已经属于深度学习的范畴了，我要在这么短的时间里面构建出一个模型出来，而且还不能保证识别率，我毫无头绪。后来我就去上网到处搜罗资料，对于文字识别的基本上就两个方向：
1. 基于openCV的深度识别模型，需要自己训练
2. 使用windows Tablet PC SDK 提供的接口

第一个显然超出了我的能力范围，我就去找第二个的资料，但是很可惜，除了官方文档，几乎找不到什么通俗易懂的资料。而且既然要使用 windows 的接口，那就说明我的代码只能在windows上面跑，万一老师用的Mac怎么办？

就在我感觉走投无路的时候，老师在群里说了可以使用win的API，这让我突然一下就不纠结了。这个时候，我正好看了有一篇七八年前的帖子，讲了他自己是怎么调用接口的，好歹也有参考价值，就开始硬着头皮写了。

想到联网是因为老师最后一次课就是教的Qt http的应用，给了提示和方法。

# 代码框架解析

以下是我的代码的整体框架：
![](https://oss-liuchengtu.hudunsoft.com/userimg/be/bea64d102fbf4b50c9b0f38ee6484879.png)

加入了联想词的功能之后，就多了以下几个模块：
![](https://oss-liuchengtu.hudunsoft.com/userimg/7c/7c2fd46b16f5136f95e80ee540dd289c.png)



## 主窗口的设计

主窗口的设计也碰到了一些弯弯绕绕的事情。我的思路就是先准备好需要用的所有组件啊，容器啊，布局呀之类的控件，然后再通过布局管理器在主窗口上进行布局。
最开始所有的事情全部是在构造函数里面执行的，该写的不该写的全部在构造函数里面。头文件里面就一个空的声明，连成员变量都不在头文件里面，直接在构造函数的时候加入到布局里面。
后来想要继续实现功能的时候就遇到大麻烦了，在除了构造函数之外的成员函数想要直接用主窗口的控件的时候，直接用不了，得用findchild或者findChildren在布局或者容器里面一个一个找，太麻烦了，而且我不止要找一次，这样会严重影响程序的执行效率。
怎么解决呢，当然是把所有控件都在头文件里面作为成员变量直接定义，但是我暂时不分配空间，只是分配空指针。然后又重构了主窗口的代码。这样一来，控件就不仅仅只是在布局中存在了，直接通过成员变量的指针，就能够直接访问了。
但是new出来的空间如果析构的时候没有正确处理会导致内存泄漏，那么究竟应该怎么安排析构函数呢。我看的参考书上面这样说：
![](https://oss-liuchengtu.hudunsoft.com/userimg/7b/7b2676e841aecff7a081f3493e48bc2d.jpg)
也就是说布局中的控件自动成为布局的容器的子对象，这个对象树是自动构建的。那么按照对象树的特性，析构父对象的时候，会自动析构子对象，所以析构函数里面只需要delete一个中心容器就可以了，还有子窗口的指针也需要额外判断。所以析构函数的代码结构为：
```cpp
HandWirttingInput::~HandWirttingInput()
{
    if (chaListWindow != nullptr) //符号表子窗口已经正确创建
    {
        delete chaListWindow;
    }
    //......其余子窗口的判断同上

    delete centralWidget;
 //删除主窗口的中心部件
}
```

首先需要对主窗口构建一个合理的布局，我实现的布局如下：
![](https://oss-liuchengtu.hudunsoft.com/userimg/ae/ae88ae02bf9a16808996b96a67f003e3.png)
按照这个布局，首先需要创建一个容器（QWidget）指定为中心部件，如果不设置中心部件的话，即使在这个容器里面实现了布局，运行出来还是什么都没有。我就遇到了这个问题。
那么，需要的控件就一目了然了。
```cpp
private:
    //CharacterList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapCharList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
    MapNumList* numListWindow = nullptr;
    MapEngList* engListWindow = nullptr;
    Setting* setting = nullptr;


    //准备页面布局的所欲需要用到的控件指针，本来是在构造函数里面处理的，但是总觉得这样不好直接访问，使用findchild()并不是一个很高效率的方法
    //所以先定义所有需要布局的，布局控制、容器、以及控件指针
    QWidget* centralWidget = nullptr; //中心部件的容器
    QGridLayout* centralplay = nullptr; //中心布局

    //顶部的文本编辑器 控件
    QTextEdit* textEdit = nullptr;

    //-------------- 左 ——————————————————
    QWidget* leftContainer = nullptr;
    QVBoxLayout* leftplay = nullptr;

    QPushButton* contrlBtn = nullptr;
    QPushButton* singleRecBtn = nullptr;
    QPushButton* multipRecBtn = nullptr;
    QPushButton* eraseBtn = nullptr;
    QPushButton* rewriteBtn = nullptr;

    //-------------- 中 ——————————————————
    QWidget* midContainer = nullptr;
    QVBoxLayout* midplay = nullptr;
    QLabel* writeZone = nullptr;

    //-------------- 右 ——————————————————
    //在MainWindow里面创建QWidget容器管理布局
    QWidget* rightContainer = nullptr;

    //网格布局
    QGridLayout* rightplay = nullptr;

    // 添加组件
    QPushButton* btn1 = nullptr; //识别之前默认候选栏都是空值
    QPushButton* btn2 = nullptr;
    QPushButton* btn3 = nullptr;
    QPushButton* btn4 = nullptr;
    QPushButton* btn5 = nullptr;

    QPushButton* charBtn = nullptr;
    QPushButton* numBtn = nullptr;
    QPushButton* EnBtn = nullptr;
    QPushButton* CnBtn = nullptr;
```

关于控件之间的布局和关系，就是构造函数里面要做的事了，如下图所示：
![](https://oss-liuchengtu.hudunsoft.com/userimg/da/dad71ddd86b0f9cf6eaab6d90da67735.png)

后来加入==联想词==的候选栏之后，中心布局就多了一行，具体的布局如下：
```cpp
//_______________________________________________________________________
SugContainer = new QWidget;
Sugplay = new QHBoxLayout(SugContainer);

Sugbtn1 = new QPushButton("");
Sugbtn2 = new QPushButton("");
Sugbtn3 = new QPushButton("");
Sugbtn4 = new QPushButton("");

Sugplay->addWidget(Sugbtn1);
Sugplay->addWidget(Sugbtn2);
Sugplay->addWidget(Sugbtn3);
Sugplay->addWidget(Sugbtn4);

Sugbtn1->setSizePolicy(policy);
Sugbtn2->setSizePolicy(policy);
Sugbtn3->setSizePolicy(policy);
Sugbtn4->setSizePolicy(policy);


centralplay->addWidget(SugContainer, 1, 0, 1, 3);
```


## 符号列表窗口设计

由于右下角这三个按钮的事件处理和实现思路基本一致，所以只拿第一个特殊符号列表为例子进行思路的阐述。
![](https://oss-liuchengtu.hudunsoft.com/userimg/46/46d94bc0b1f7cc32ff831ff754dd3539.png)

我希望按下这个按钮，会弹出一个窗口，这个窗口里面有很多个字符按钮，当我按下某一个按钮之后，这个弹窗会自动隐藏并将文本信息直接写入到主窗口的`TextEdit`当中。

于是，我需要设计一个单独的弹窗，封装在一个类`MapCharList`当中，这个类继承自QWidget。为什么不是Qdialog，其实我当时也是纠结了一会，感觉都可以的。
很明显这个类的中心容器就是它自己，不需要额外指定中心容器，然后我希望符号按钮是整齐排列的，所以必定是网格布局：
![](https://oss-liuchengtu.hudunsoft.com/userimg/a8/a8d08e89f58da551c0e4927e71c015ff.png)

再定义一个网格布局`charplay`。

这个时候就碰到了一个很典型的问题了，如上图，一共有`9*5`个功能相似的按钮，我是一个一个老老实实手动 new 几十个按钮然后再一个个添加到布局，然后再创建几十个信号和对应的槽函数呢，还是另外去寻找更为巧妙的方法去处理这样批量且重复的事件呢？

很显然我更愿意是后者，因为前者实在是太笨了，现在我只有几十个按钮可以手动添加，那如果有几千个几万个，还是得寻找新的方法去管理。

这个管理的方法，就是==使用QSignalMapper去批处理这样重复的组件==。

我去查看官方文档的时候，我发现它给的例子，对应上了我需要的代码逻辑。

需要预先设定好每一个按钮的文本信息，它会和按钮一起映射到Map当中，只要Map里面有一个按钮被点击了，Map就会自动发出信号，这个信号携带一个类型为`QString`的参数，这个参数的值就是被点击的按钮的文本。

对于每一个按钮，设定好Text属性之后，就要将每个按钮的 `clicked()` 信号连接到 `QSignalMapper` 的 `map()` 槽函数，这一步是必须的，如果不这么做，按钮点击的时候，Map及那个不会发出任何信号。
连接好之后才是添加按钮映射。
最后根据需要，再布局当中直接添加这个按钮的组件。
```cpp
//首先使用buttonTexts存储每一个按钮的文本信息
QStringList buttonTexts;
buttonTexts << "，" << "。" << "、" << "；" << "：" << "？" << "！" << "·" << "···"
			<< "——" << "~" << "‘’" << "“”" << "/" << "\\" << "_" << "··" << "--"
			<< "," << "." << "''" << "\"\"" << "?" << "!" << "`" << "+" << "-"
			<< "@" << "#" << "$" << "￥" << "^" << "&&" << "*" << "()" << "[]"
			<< "{}" << "<>" << "|" << "%" << ";" << "℃" << "⟪⟫" << "→" << "←";

//在当前QWidget里面添加网格布局管理器
charplay = new QGridLayout(this); //父布局是this

//创建Map 
signalMapper = new QSignalMapper(this);

for (int i = 0; i < buttonTexts.size(); i++)
{
	QPushButton* btn = new QPushButton(buttonTexts[i]);
	connect(btn, SIGNAL(clicked()), signalMapper, SLOT(map()));  //将每个按钮的 clicked() 信号连接到 QSignalMapper 的 map() 槽函数
	signalMapper->setMapping(btn, buttonTexts[i]);
	charplay->addWidget(btn, i / 9, i % 9, 1, 1);
}
```
这个方法真的非常巧妙了，让代码的逻辑更加优美简洁，并且让信号处理变得更加简单清晰。

现在，假设点击了某个按钮，Map发出了信号，这个信号交由谁去处理？主窗口能直接接收到这个信号吗？我觉得主窗口要直接操作Map信号的话，有点不太好，所以中间加了一道信号转发的链接。下面的代码当中，`this` 就是这个字符列表子窗口。
```cpp
//信号连接信号， 信号转发
connect(signalMapper, SIGNAL(mapped(const QString &)), this, SIGNAL(doclicked(const QString &)));
```
其中子窗口类定义里面有信号：
```cpp
signals:
	void doclicked(const QString& text);  //Map()发出信号之后，会转发信号到doclicked信号，携带一个按钮文本作为参数
```
现在，主窗口再处理`doclicked` 信号就可以了。

这个时候又出现了一个问题，就是信号与槽的链接时机。我在主窗口里面是分配了一个指针用来指向子窗口，但是最开始是空指针，是没有被实例化的：
```cpp
MapCharList* chaListWindow = nullptr; //主窗口里面添加一个子窗口的指针
```
什么时候被实例化呢，只有在我第一次点击`charBtn`的时候会被实例化，主窗口构造函数里面做了如下链接：
```cpp
QObject::connect(charBtn, &QPushButton::clicked, this, &HandWirttingInput::open_closeCharacterList);
```
而`open_closeCharacterList)`的定义结构如下：
```cpp
//处理字符按钮
void HandWirttingInput::open_closeCharacterList() //单击打开窗口，再次点击关闭窗口
{
    if (chaListWindow == nullptr)
    {
        chaListWindow = new MapCharList(this); //设置子窗口的父对象是this

        chaListWindow->show();
        //........添加其他处理逻辑
    }
    else
    {
        if (chaListWindow->isVisible()) 
        {
            chaListWindow->hide();  // 隐藏窗口
            //........添加其他处理逻辑
        }
        else 
        {
            chaListWindow->show();  // 显示窗口
            //........添加其他处理逻辑
        }
    }


}
```
只有按钮第一次被点击的时候会被实例化，在之后窗口会根据需要隐藏起来，如果某次运行不点击按钮，是永远都不会被实例化的。

那么现在就有两种选择，一种是在实例化完之后立马链接主窗口和子窗口的信号与槽，一种是在子窗口的构造函数里面。两种方法其实都可以，我选择后者。
`this`是子窗口对象。
```cpp
//子窗口和父窗口链接 
QObject::connect(this, SIGNAL(doclicked(const QString & )), this->parent(), SLOT(inputCharButton(QString)));
```
主窗口的槽函数结构如下，不使用append主要是因为他会自动换行，不符合输入习惯：
```cpp
//接收来自字符串窗口的信号，并处理
void HandWirttingInput::inputCharButton(const QString& btntext)
{
    //textEdit->append(btntext);  //每次选择一个字符之后，界面就会自动隐藏 append()会自动换行
    textEdit->insertPlainText(btntext);
    chaListWindow->hide();
    //.....添加其他逻辑
}
```
至此，符号表的设计逻辑就非常清晰了。
数字表和字母表是一样的思路，不做赘述。


## 识别器设计

解决这一个模块的时候真的找了很多参考资料，然后我发现用`c#`去调用win API的例子还是蛮多的，但是出现了很多概念，比如说什么是COM，什么叫做COM实例化，为什么需要COM。因为我在阅读微软的官方文档的时候，出现了这些概念，查了很多资料也没有一个让我很明白的解释，但是我的大概理解就是：使用一个接口的时候，首先需要实例化这个接口，但是这个接口要能够支持被各种语言调用，这个时候就需要COM。

API在哪里，怎么调用？我是一个超级小白，我最开始确实搞不明白这个东西，我以为win的API是需要自己下载SDK然后安装的，或者自己在网上找库。后来苦苦寻找，找到了这个组件的SDK下载的官网，诶，浏览器拦截了不让下载。关了病毒检测继续下，安装的时候报错版本不兼容，装不了。就在我以为要完蛋的时候，我注意到了官方文档中的那一句 “XX方法，标头`#include <msinkaut.h>`”，此时我的脑子里有一个大胆的想法，我去那个古老的SDK网站上瞄了一眼，发现他是支持win XP的，但是我的系统是win 11，已经更新迭代很多次了。我又想起上次大作业做字符串检索的时候，里面用到的"内存映射文件技术"就是包含了一个win的头文件，然后直接调用的接口，那是不是说明其实高版本的win系统已经集成了很多原来需要另外下载的SDK呢？为了验证这一想法，我直接在头文件里面加上了`#include <msinkaut.h>`，没有报错，编译通过，那么直接开始用里面的接口和方法就好了，就是操作系统自带的。真的，弯弯绕绕这么多，没想到这么简单，同时也感叹win操作系统真是强大。

好了，准备工作就绪，现在步入正题！
（参考了很多资料，会在最后放上对我帮助非常大的博客或者仓库链接，感谢互联网大佬们）

整体的识别器设计思路，大概就是：
1. 主窗口在构造出实例的时候，就要携带一个成员`inputs`，这个成员就是识别器类`HansInput`的实例.
2. 初始化`inputs`的时候，需要传入一个`HWND`的句柄，说的通俗一点，就是某个窗口或者控件的`winId`。很显然，只有指定了识别器的识别区域，它才知道要在哪里去收集、显示、识别墨迹。
3. 识别器识别函数的调用时机，为了更好的用户体验，我设计识别区域的组件响应鼠标左键的释放事件，每次写完一笔，就会调用识别器的识别方法，用户看来就做到了实时更新。
4. 结果的存储和显示，每次识别的结果，可能是单个的字符，也可能是多个的字符，所以自定义一个结构体用来存放每一次的识别结果。这个数据结构也是放在了主窗口里面，和识别器结合，共同管理结果。

既然要管理识别结果，就需要一个数据结构保存结果，所以就定义了以下结构体：
```cpp
struct InputRes
{
	char res[128]; //用于保存每一次识别的结果
};

typedef std::vector<InputRes> InPutResS; //保存候选项
```

遇到hi对于识别器，就有看了如下类定义：
```cpp
class HansInput : public QWidget
{
	Q_OBJECT

public:
	explicit HansInput(QWidget *parent = nullptr);  
	~HansInput();

	//定义接口指针 p_前缀表示指针 构造函数时去初始化
	IInkCollector* p_IInkCollector = nullptr; //墨迹收集和管理
	IInkDisp* p_IInkDisp = nullptr;  //墨迹显示
	IInkRecognizerContext* p_IInkRecognizerContext = nullptr;  //墨迹识别

	void inputInit(HWND hwnd);  //初始化接口等，需要传入一个ui组件的指针，来指定墨水收集和识别的区域
	void RecogData(InPutResS& Res); //墨迹识别
	void releaseUp();  //释放与墨迹输入相关的接口资源，清理COM
	void clear(); //清除所有笔划

	void clearNew(); //清除最新的一笔，回退一笔


signals:
	//发出信号，表示已经正确删除笔划集合并且更新了UI界面，希望main窗口能够再次调用一次识别函数，将结果反馈给用户
	void deleteLast();



private:
	Ui::HansInputClass ui;
};
```
成员变量和成员函数的职责在上面代码的注释里面都清晰地写出来了，关于信号与槽的链接后面会细讲。

主窗口里面先要将识别器初始化，这个是在构造函数里面完成的：
```cpp
//______________________ 识别器初始化 _________________________
WId hshow = writeZone->winId();
inputs.inputInit((HWND)hshow);
```
需要将控件的句柄作为参数传递到识别器初始化的函数里面。

`HRESULT` 是一个在 Windows 编程中广泛使用的类型，它表示函数调用的成功或失败状态。
```cpp
HRESULT hr;  //表示函数调用成功或者失败的状态
```
之后会大量使用这个变量来检查代码。

还需要初始化COM，对于为什么要执行下面这个代码，我也不清楚底层原理，我只知道，没有这句代码，后面就可能跑不通。
```cpp
hr = CoInitialize(nullptr);  //初始化COM接口  LPVOID == void*
if (FAILED(hr))
{
	qDebug() << "Failed to CoInitialize()";
	return;
}
```
贴上AI的解释和大佬们的解释，因为我自己解释不清楚。
![](https://oss-liuchengtu.hudunsoft.com/userimg/55/5597308770252e22b5f6536f6b0ee699.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/4c/4c17ed696839a71f579bdf9ecca61d1d.png)

接口这个东西要实例化才能用，所以还需要请求 COM 框架创建一个 IInkRecognizerContext 接口的实例，并返回该接口的指针。前四个参数是输入型参数`[in]`，最后是`[out]`，这个指针是识别器里面的成员变量，执行完这句之后，这个指针就指向了接口实例了，之后的操作中就可以正常调用接口中的方法：
```cpp
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
```
创建墨迹收集接口的实例的时候也是这样：
```cpp
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
```
完成接口实例化之后，接下来要做三件事情：
1. 获取墨迹对象的指针，保存在成员变量`p_IInkDisp`中。
2. 将书写区域的句柄关联到墨迹收集器中。
3. 打开墨迹输入开关。

具体代码如下：
```cpp
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

//打开墨迹输入开关
hr = p_IInkCollector->put_Enabled(VARIANT_TRUE);
if (FAILED(hr))
{
	qDebug() << "Failed to put_Enabled(VARIANT_TRUE)";
	return;
}
```
准备工作终于完成之后，接下来是识别器实现墨迹识别的核心：

墨迹笔划怎么去访问？ 如下，自定义一个指针去管理笔划集合：
```cpp
//获取指向墨迹收集器的指针，这个收集器是整个墨迹的快照
IInkStrokes* p_IInkStrokes = nullptr;
HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //可以通过p_IInkStrokes访问和操作墨迹笔划集合。
```
墨迹收集的工作需要这个笔划集合作为参数：
```cpp
hr = p_IInkRecognizerContext->putref_Strokes(p_IInkStrokes);  //设置识别上下文中将要进行识别的墨迹笔划集合
```
接下来就是最核心的墨迹识别代码了：
```cpp
//识别
IInkRecognitionResult* p_IInkRecoResult = nullptr;
InkRecognitionStatus RecognitionStatus = IRS_NoError;  //COM 接口，代表墨迹识别的状态

hr = p_IInkRecognizerContext->Recognize(&RecognitionStatus, &p_IInkRecoResult);  //识别器会返回结果 在形参列表里面引用返回
```
在候选项里面截取需要的部分加入到墨迹识别结果集当中：
```cpp
IInkRecognitionAlternates* p_IInkRecognitionAlternates;    //-s

hr = p_IInkRecoResult->AlternatesFromSelection(
				0,                                 //选择的起始索引  这里 0 表示从第一个候选词开始检索          in
				-1,                                //选择的结束索引  -1 通常用于指示直到列表末尾的最后一个候选词  in
				5,                                 //要检索的候选词的最大数量  即返回具有 5个候选词的结果        in
				&p_IInkRecognitionAlternates       //指向候选词集合                                         out
);
```
将获取的结果转成UTF8的编码格式存储在Res当中。
```cpp
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
```
结果保存之后，一定要释放这个过程中 中间实例化的一些接口。
```cpp
p_IInkRecognitionAlternate->Release();
p_IInkStrokes->Release(); 
```
还要重置识别器的内容，为下次识别做准备：
```cpp
//重置识别器的内容
p_IInkRecognizerContext->putref_Strokes(nullptr);
```
每次识别完了之后，`p_IInkDisp `都是保存了数据的，如果不及时清空，会影响到下一次识别的结果。所以成员函数定义如下：
```cpp
void HansInput::clear() //清除所有笔划
{
	p_IInkDisp->DeleteStrokes(nullptr);
	qDebug() << "Delete Strokes";
}
```
接下来要完成第三步，也就是识别调用时机。想要在鼠标每次释放的时候，手写区域都会响应这个鼠标释放的事件，然后完成指定的操作。这个场景当中，不仅指定了控件，而且指定了事件。某个控件只响应某个事件，这不就是事件过滤器的使用场景吗。

所以，思路就是：
1. 主窗口重写一个事件过滤器，指定手写区域的控件响应鼠标释放事件。
2. 事件过滤器如果发现组件和事件都能匹配上，就发出一个自定义的信号，如下：
```cpp
signals:
    void MouseRelease();  //每一笔写完之后，通过事件过滤器发出信号
```
这个信号链接一个槽函数：
```cpp
//WriteZone响应鼠标释放事件
QObject::connect(this, &HandWirttingInput::MouseRelease, this, &HandWirttingInput::mouseReleaseEvent);
```
槽函数`mouseReleaseEvent`的定义如下，这样就做到了实时识别，并且会将每一次识别的结果都更新到候选按钮的显示文本当中：
```cpp
//每一个笔划的结束都会调用识别功能
void HandWirttingInput::mouseReleaseEvent()   //void MouseRlease()信号发出之后，会调用这个槽函数，然后在里面调用识别功能
{
    qDebug() << "mouseReleaseEvent connect.";

    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
    btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
    btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
    btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
    btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));

}
```
我希望每个候选按钮点击的时候，都会将文本发送到TextEdit当中，也要进行槽函数的链接：
```cpp
//候选字按钮被按下
QObject::connect(btn1, &QPushButton::clicked, this, &HandWirttingInput::btn1Clicked);
```
槽函数定义如下：
```cpp
//按下候选词的按钮，输入文字到textEdit
void HandWirttingInput::btn1Clicked()
{
    qDebug() << "btn1Clicked";

    textEdit->insertPlainText(btn1->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
    
}
```
这个里面都对重写按钮的click()处理，所以我需要实现准备一个重写按钮被按下后的槽函数实现：
```cpp
//按下重写按钮
void HandWirttingInput::btnClearClicked()
{
    qDebug() << "btnClearClicked";

    textEdit->setFocus();
    inputs.clear();  //只是删除笔触，之后在析构的时候才会删除所有资源

    writeZone->clear();

    btn1->setText("");
    btn2->setText("");
    btn3->setText("");
    btn4->setText("");
    btn5->setText("");

    tempRes.clear();

}
```

至此，一个简单的墨迹识别器就设计完成了。


## “退一笔”功能设计

有了前面的设计经历，这个其实就是要对笔划集合做维护，在识别器里面定义一个方法，能够删除某个时刻笔划集合里面的最后一笔，但是需要注意一些细节。

第一步，获取笔划集合：
```cpp
//获取墨迹笔划集合
IInkStrokes* p_IInkStrokes = nullptr;
HRESULT hr = p_IInkDisp->get_Strokes(&p_IInkStrokes);  //out
```
第二步，获取笔划数量：
```cpp
//获取笔划数量
long count = 0;
p_IInkStrokes->get_Count(&count);
```
获取数量之后一定要特判一下，笔划的数量为0的时候就直接返回，不然再删除就会越界。
```cpp
hr = p_IInkDisp->DeleteStroke(p_lastStroke);   //删除最后一笔
```
到这里就完事了吗，不，能够执行到这一步说明确实删除了笔划，但是用户感受不到，因为UI界面没有更新，墨迹依然停留。所以，还有记得更行UI界面：
```cpp
//删除笔划集合之后，要保证能够更新到UI
LONG_PTR curHWND = 0;
hr = p_IInkCollector->get_hWnd(&curHWND);

if (SUCCEEDED(hr))
{
				HWND hwnd = reinterpret_cast<HWND>(curHWND);
				hr = InvalidateRect(hwnd, NULL, TRUE);
   //刷新手写区域

				if (FAILED(hr))
				{
					qDebug() << "InvalidateRect(hwnd, NULL, TRUE)";
					return;
				}

}
```
结束了吗？还没有，因为候选框的状态还没有更新，删除了一笔之后也要进行重新识别的，所以再加上：
```cpp
//重新识别信号
emit deleteLast();
```
这个信号发出，执行主窗口的槽函数：
```cpp
//更新识别
QObject::connect(&inputs, &HansInput::deleteLast, this, &HandWirttingInput::deltUpdate);
```
deltUpdate的定义如下：
```cpp
//HansInput发过来的信号，
void HandWirttingInput::deltUpdate()
{
    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    //删除最后一笔时，由于删除之后自动识别，此时画布上面什么也没有，那么结果数组temRes里面是没有任何元素的，于是访问元素下标时不合法的
    //下面的if做一个特判
    if (tempRes.size() >= 5)
    {
        btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
        btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
        btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
        btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
        btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));
    }
    else   //画布为空的时候
    {
        btn1->setText("");
        btn2->setText("");
        btn3->setText("");
        btn4->setText("");
        btn5->setText("");
    }

    qDebug() << "After Delete, the results has been UPDATE.";
}
```
一定要特别注意删除最后一笔的时候，画布为空，识别结果的数组自然也没有元素，所以再去用下标访问就会造成越界行为，所以要对返回的识别结果的数组长度做特判。

## 重写功能设计

重写功能要做3件事：
1. 清空画布
2. 清空候选按钮的文本内容
3. 清空联想词搜索的内容

同时要注意清空识别的结果和笔划集合，为下一次识别做准备：
```cpp
//按下重写按钮
void HandWirttingInput::btnClearClicked()
{
    qDebug() << "btnClearClicked";

    textEdit->setFocus();
    inputs.clear();  //只是删除笔触，之后在析构的时候才会删除所有资源

    writeZone->clear();

    btn1->setText("");
    btn2->setText("");
    btn3->setText("");
    btn4->setText("");
    btn5->setText("");

    Sugbtn1->setText("");
    Sugbtn2->setText("");
    Sugbtn3->setText("");
    Sugbtn4->setText("");

    tempRes.clear();

}
```





## 设置窗口

更改墨迹颜色，墨迹粗细以及候选字的样式，布局使用网格布局。
![](https://oss-liuchengtu.hudunsoft.com/userimg/be/bede4c473044ca6ccc71b9e577761f95.png)

需要管理墨迹，毫无疑问是需要API的，可以通过下面的代码，来获取墨迹的样式，然后修改。下面的代码的作用是将墨迹颜色改为红色：
```cpp
IInkDrawingAttributes* p;
HRESULT hr;
hr = inputs.p_IInkCollector->get_DefaultDrawingAttributes(&p);
```
修改墨迹宽度，只需要及那个下面代码的括号里面的参数修改一下，就可以了，其中30表示30px：
```cpp
p->put_Width(30);
```
修改按钮字号的时候，只需要：
```cpp
QFont font("宋体", 10);
btn1->setFont(font);
```
接下来就是信号与槽的连接了，每一个按钮都对应立刻一个点击信号，这个信号发送到主窗口中，然后执行对应的槽函数：
```cpp
//修改颜色
QObject::connect(setting, &Setting::btnblackclicked, this, &HandWirttingInput::setBlack);
//......修改其他颜色

//修改宽度
QObject::connect(setting, &Setting::btn1clicked, this, &HandWirttingInput::setWidth1);
//......修改其他宽度

//修改字号
QObject::connect(setting, &Setting::btn10clicked, this, &HandWirttingInput::setSize1);
//......修改其他字号

//恢复默认设置
QObject::connect(setting, &Setting::reSetBtnclicked, this, &HandWirttingInput::reSet);
```

信号与槽的链接需要注意时机，只有在设置窗口被实例化之后的链接才是有效的。处理操作和前面的符号表窗口一样。


## 细节处理

细节处理主要是点击按钮的时侯，颜色会发生变化，更好的与用户进行交互，具体演示请看测试文档。


## 联想词候选栏设计

~~这个目前还没事件落实，要准备期末考试了，就一边准备期末考试一边找资料然后构思一下这两个扩功能怎么做吧。~~

期末周结束了，正好还剩下几天可以试试联网识别的功能。
虽然流程上看上去很简单看，但是中间还是碰到了很多问题，容我细细道来：

既然要使用第三方的api，那么肯定是要仔细筛选的，有访问次数限制的首先淘汰。但是剩下来的选择就不多了。在课堂上老师讲过很多api的响应结果都应该该是一个标准的Json格式的数据，课堂练习我也写了，如果所有响应结果都是这样的话就好了，但是我找到的api大多数格式都是JsonP的模式。也就是说，返回的`QNetworkReply* reply` 转换成`QByteArray`之后不能直接转换成`QJsonDocument`进行解析。具体应该如何拿到里面包装的Json数据，就根据网站的响应结果而确定了。

比如：我最开始选用的是百度的联想词搜索的API，但是我后来发现：
[suggestion.baidu.com/su?wd=关键字&cb=window.baidu.sug](http://suggestion.baidu.com/su?wd=%E5%85%B3%E9%94%AE%E5%AD%97&cb=window.baidu.sug)
响应结果不是UTF-8的编码，一度让我的终端出现乱码，后来是使用了Qt里面编码转换的方法，才能够正常显示；但是这个问题还没有结束，后来我发现，他的响应结果并不是标准的Json格式，这凭空增加了我解析数据的难度，无奈之下只好弃用，寻找更合适的api。
![](https://oss-liuchengtu.hudunsoft.com/userimg/42/42172a2c971d53322cb8c42fdbe8d25b.png)

![](https://oss-liuchengtu.hudunsoft.com/userimg/c2/c2e91cdee0a01d2703af00bb9adfa09e.png)

天无绝人之路，最后选择了`https://sug.so.360.cn/suggest` 的api，编码是UTF-8：
![](https://oss-liuchengtu.hudunsoft.com/userimg/f4/f4eb196bc7a2e1b322875d5422c6b98d.png)
返回的数据最外围包了一层`window.so.sug({Json数据})`，最后要进行处理的话也相对简单。
以下是数据格式：
![](https://oss-liuchengtu.hudunsoft.com/userimg/b7/b7f9737914e23d65e8e5b8421a9fa3e3.png)


对于数据的存储只需要设置`Suggestion`类和`SugResult`类，类定义如下：
```cpp
class SugResult
{
public:
	QString m_word;
};
```
```cpp
class Suggestion
{
private:
	int m_errorcode;
	QString m_ext;
	QString m_query;

	QVector<SugResult> m_result;

	QString m_src;
	QString m_ssid;
	QString m_version;


public:
	void setErrorcode(int code);
	void setExt(QString ext);
	void setQuery(QString que);

	void setSugresult(QVector<SugResult> sugr);

	void setSrc(QString src);
	void setSsid(QString ssid);
	void setVersion(QString ver);

	//将对象恢复至无内容的状态
	void toNULL();

	 

	//__________________________________
	int getErrorcode();
	QString getExt();
	QString getQuery();

	QVector<SugResult> getSugresult();

	QString getSrc();
	QString getSsid();
	QString getVersion();

	//___________________________________
	//赋值运算符重载
	void operator = (const Suggestion& other);


};
```

所以现在主窗口当中还需要实例化三个成员，分别是：
1.  数据成员`Suggestion suggestions;  //存放联想结果`
2.  请求管理者 `HttpRequestManager httpRequestManager; //管理http请求类`
3.  响应结果管理者 `HttpReplyHandler httpReplyHandler;  //处理和解析http请求结果`


`http` 请求还需要定义一个请求管理类来管理请求，在设计的过程当中需要注意的是：由于是自定义查询，后面会跟上类似`?encodein=utf-8&encodeout=utf-8&format=json&word=关键字&callback=window.so.sug` 的要求，其中最关键的是`word=#content#` ，替换之后，就能变成任何想要的关键词的联想结果。所以设计请求管理类的时候要能够做到自定义查询的功能。
```cpp
class HttpRequestManager  : public QObject
{
	Q_OBJECT

public:
	HttpRequestManager(QObject *parent = nullptr);
	~HttpRequestManager();

	void sendGetRequest(const QUrl& url);


signals:

	//finished() 信号有一个参数，即 QNetworkReply* 类型的指针，指向完成的网络请求的回复对象
	//所以在传递信号的时候一定要指示参数

	//需要包含QNetworkReply类的完整定义 使用#include<>，而不是class+类名
	void requestFinished(QNetworkReply* reply);

private:
	QNetworkAccessManager m_httpManager;


};
```
在调用`sendGetRequest(const QUrl& url)` 方法之前，默认QUrl 变量是已经经过自定义查询处理的，那么自定义查询QUrl的初始化时机应该在什么时候呢？

联想一下，每一次释放鼠标，都会做一次识别，然后都会同步返回一个识别结果，这个识别结果的第一个就是当次识别相似度最高的识别结果，拿这个结果再去作为关键字联网查询的体验最好。所以应该在每一次识别完成之后，都发出一个信号`ReadySuggest()`，这个信号连接到某一个槽函数执行自定义查询的初始化然后将调用Manager类管理http请求。
所以鼠标释放的槽函数就定义为：
```cpp
//每一个笔划的结束都会调用识别功能
void HandWirttingInput::mouseReleaseEvent()   //void MouseRlease()信号发出之后，会调用这个槽函数，然后在里面调用识别功能
{
    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes); //识别结果获取之后，再发出信号请求联网识别

    //......其他逻辑
   

//**********************************************************
    //候选词填充完成之后，再发出信号请求联网识别
    emit ReadySuggest(); 
}
```
一旦主窗口接收到这个信号就转到槽函数`ReadySuggestEvent`, 信号槽的链接如下：
```cpp
//联想识别
QObject::connect(this, &HandWirttingInput::ReadySuggest, this, &HandWirttingInput::ReadySuggestEvent);
```
在`ReadySuggestEvent`里面对url添加自定义查询。
```cpp
    QString queryContext = btn1->text(); //获取最优的识别结果，联网做关键字联想查询
    //QString queryContext = QString::fromUtf8(QByteArray(tempRes[0].res)); //获取最优的识别结果，联网做关键字联想查询  QString::fromUtf8(QByteArray(tempRes[0].res))

    QUrl url("https://sug.so.360.cn/suggest");

    QUrlQuery query; //添加自定义查询
    query.addQueryItem("encodein", "utf-8");
    query.addQueryItem("encodeout", "utf-8");
    query.addQueryItem("format", "json");
    query.addQueryItem("word", queryContext);
    query.addQueryItem("callback", "window.so.sug");
    url.setQuery(query);

httpRequestManager.sendGetRequest(url);  //发送请求

```
到这里有一个需要注意的是，联网请求是异步的，也就是说如果接下来直接试图访问请求结果，并将成员`httpReplyHandler`的处理结果直接赋值给数据成员`suggestions` 会导致请求尚未完成响应，`httpReplyHandler` 里面的成员还是空的时候，就直接赋值给了`suggestions`，就导致了联网响应请求成功，但是数据并没有在正确的时机被复制给成员，导致接下来的所有操作都将是错误的。

解决这个问题的办法就是使用事件循环保证在`httpReplyHandler`响应完成之后，发出某种信号，然后主线程接收到这个信号之后才开始进行`suggestions`的赋值操作，这样就能保证里面的数据一定是有效的。

最开始的实现如下：
```cpp
 //httpReplyhandler自动解析数据 解析完成之后会发送suggestionsReady的信号
   // 只有在接收到这个信号的时候才更新联想结果

    QObject::connect(&httpReplyHandler, &HttpReplyHandler::suggestionsReady,
       [&loop, this](Suggestion http_suggestions) {
           this->suggestions = http_suggestions;
           loop.quit();  // 退出事件循环
       });


    //联网结果没有返回之前就执行了emit UpdateSuggestions(); 导致检索结果其实是空的，所以具有之后性，
    //要保证返回的结果是有效的，才能够执行发送信号的语句

    
    //发送信号，表示联想词更新已完成，准备显示到按钮文本上
    emit UpdateSuggestions();
```
但是这样又出现了一个问题，就是联想识别的结果落后一个笔划，就比如我画了三条横线，手写识别已经到了“三”，但是联想识别的结果里面的关键词才到“二”，并且不由等待时间决定，只有当我开始写下第四笔的时候，联想结果才开始改为“三”作为关键词。可见不是网络的问题，而是同步逻辑没有处理好。

仔细查看上述代码会发现，虽然确实是保证了`suggestions`里面的数据是有效的，但是发送
信号`UpdateSuggestions()` 的时机不对，导致后面的步骤不等待完成联想就开始执行了。也就是说明了，赋值操作和发送信号的操作应该是具有原子性的，是不应该分割的，并且都在接收到`suggestionsReady`信号之后开始执行。这样就能保证手写识别的结果和联网查询的结果的同步性。

所以`ReadySuggestEvent()  `槽函数的正确形式应该为：
```cpp
//联想识别功能
void HandWirttingInput::ReadySuggestEvent()  //信号ReadySuggest的槽函数
{
    QString queryContext = btn1->text(); //获取最优的识别结果，联网做关键字联想查询
    
    QUrl url("https://sug.so.360.cn/suggest");

    QUrlQuery query; //添加自定义查询
    query.addQueryItem("encodein", "utf-8");
    query.addQueryItem("encodeout", "utf-8");
    query.addQueryItem("format", "json");
    query.addQueryItem("word", queryContext);
    query.addQueryItem("callback", "window.so.sug");
    url.setQuery(query);

    qDebug() << "queryContext : " << url;

    httpRequestManager.sendGetRequest(url);  //发送请求

    QObject::connect(&httpReplyHandler, &HttpReplyHandler::suggestionsReady,
        [this](Suggestion http_suggestions) {
            this->suggestions = http_suggestions;
            // 直接在这里处理数据
            emit UpdateSuggestions();  //实现同步，否则会滞后
        });

}
```

接下来就应该定义http响应结果的管理类了，已知在`QNetworkAccessManager m_httpManager` 完成响应之后会返回一个信号，这个信号带有一个参数`QNetworkReply*`指向响应结果，但是要将响应结果发送给类外，就需要定义如下的信号链接，特殊的是，这个是信号与信号的链接，但是依然可以带上参数进行传递。
```cpp
//信号链接信号
(void)QObject::connect(&m_httpManager, &QNetworkAccessManager::finished, this, &HttpRequestManager::requestFinished);
//QNetworkAccessManager::finished 信号确实带有一个参数。这个参数是一个指向 QNetworkReply 对象的指针
```
在主窗口里面会将请求者与管理者连接起来：
```cpp
QObject::connect(&httpRequestManager, &HttpRequestManager::requestFinished, &httpReplyHandler, &HttpReplyHandler::onHandleHttpReply);
```

`HttpReplyHandler`类定义如下：
```cpp
class HttpReplyHandler  : public QObject
{
	Q_OBJECT

signals:
    void suggestionsReady(Suggestion);

public:
    HttpReplyHandler(QObject* parent = nullptr);
    ~HttpReplyHandler();

    void onHandleHttpReply(QNetworkReply* reply);

    //QVector<Suggestion> getComments() const;

private:
    QJsonDocument m_jsonDoc;
    //QVector<Suggestion> m_suggestions;
    Suggestion m_suggestions;

    //将m_jsonDoc转换为类Suggestion的实例 的方法
    void PaserComment();


};
```
`m_jsonDoc`是用于解析的数据格式，`m_suggestions`则是存储解析完成之后的结果，` void PaserComment()`是内部方法，用于将`m_jsonDoc`转换为类`Suggestion`的实例 的方法。

现在，响应数据来到了`void onHandleHttpReply(QNetworkReply* reply)`方法当中，看看他是怎么处理数据的：

首先检查数据状态，方便后续排错，框架如下：
```cpp
if (reply->error() == QNetworkReply::NoError)
{
    //......处理逻辑
}
else
{
    qDebug() << "reply -> error() == true";
}
```

1. 将`QNetworkReply`里面的数据转换成字节数组：
```cpp
QByteArray responssBytes = reply->readAll();
```

2. 将字节数组转换成QString:
```cpp
QString response = QString::fromUtf8(responssBytes);
```
前面介绍过，大部分api的响应结果都是Jsonp模式的，所以要对响应的结果进行处理，处理的方法也非常简单，就是要去掉头部和尾部固定的符号就能得到一个标准JSON格式的字符串。
为此，我专门另外写了一个程序测试，保证可行之后再兼容到大作业里面的。

由下面的调试结果可以看到：
![](https://oss-liuchengtu.hudunsoft.com/userimg/e8/e8fd13dc6437cb7dacb4616f2844d29a.png)
![](https://oss-liuchengtu.hudunsoft.com/userimg/5d/5d5fac44c4b4f8606e205f131bcccf0e.png)

3. 对得到的QString字符串做处理
```cpp
//由于网站是JSonp模式的响应，所以reply返回的响应结果转成字符串不是严格类型的json格式
//需要去掉开头的 [0,13] 个字符，和结尾的后2个字符
QString newresponse = response.mid(14, -1); //从下标14开始的所有字符  -1表示到结尾
newresponse.chop(2);  //去掉最后两个字符
```
4. 将标准格式的Json字符串转换成JsonDocument类型的数据，便于后续的解析工作
```cpp
//处理之后，newresponse就是标准的json格式的字符串
        m_jsonDoc = QJsonDocument::fromJson(newresponse.toUtf8());
```
5. 检查并调用内部方法生成结果
```cpp
if (!m_jsonDoc.isObject()) //顶层类不是数组
{
    qWarning() << "Invalid m_jsonDoc";
    return;
}

PaserComment(); //对jsonDoc解析，将结果保存在Suggestions当中
```

返回的Json数据的框架为：
![](https://oss-liuchengtu.hudunsoft.com/userimg/94/944113a7eebd101e7a0054e4ff4b9d3a.png)

```json
{  
    "errorcode":0,  
    "ext":"nlpv=yc",  
    "query":"关键字",  
    "result":[  
        {  
        "word":"关键字优化"  
        },  
        {  
        "word":"关键字霸屏"  
        },  
        {  
        "word":"关键字排名"  
        },  
        {  
        "word":"关键字搜索"  
        },  
        {  
        "word":"关键字匹配"  
        },  
        {  
        "word":"关键字匹配函数"  
        },  
        {  
        "word":"关键字工具"  
        },  
        {  
        "word":"关键字的作用"  
        },  
        {  
        "word":"关键字注册"  
        },  
        {  
        "word":"关键字歌词"  
        }  
    ],  
    "src":"other",  
    "ssid":"d08c6f1c25a3491da52d780aa8675997",  
    "version":"revise"  
}
```



具体的解析操作如下：
```cpp
//将m_jsonDoc转换为类Comment的实例 的方法
void HttpReplyHandler::PaserComment()
{
    //联想词的解析逻辑
    QJsonObject jsonObject = m_jsonDoc.object();

    m_suggestions.setErrorcode(jsonObject["errorcode"].toInt());
    m_suggestions.setExt(jsonObject["ext"].toString());
    m_suggestions.setQuery(jsonObject["query"].toString());

    QVector<SugResult> tmp;

    //处理result数组
    QJsonArray resultArr = jsonObject["result"].toArray();
    for (const QJsonValue& resValue : resultArr)
    {
        if (!resValue.isObject())
        {
            qWarning() << "Invalid resValue Data.";
            continue;
        }

        QJsonObject ArrObj = resValue.toObject();
        SugResult res;
        res.m_word = ArrObj["word"].toString();
        
        tmp.push_back(res);
    }
    m_suggestions.setSugresult(tmp);

    qDebug() << "tmp.size(): " << tmp.size();

    m_suggestions.setSrc(jsonObject["src"].toString());
    m_suggestions.setSsid(jsonObject["ssid"].toString());
    m_suggestions.setVersion(jsonObject["version"].toString());

    emit suggestionsReady(m_suggestions);  //发出准备信号

}
```
发出信号suggestionsReady(m_suggestions)之后，执行：
```cpp
QObject::connect(&httpReplyHandler, &HttpReplyHandler::suggestionsReady,
    [this](Suggestion http_suggestions) {
        this->suggestions = http_suggestions;
        // 直接在这里处理数据
        emit UpdateSuggestions();  //实现同步，否则会滞后
    });
```
由于主窗口再创建的时候就连接了：
```cpp
//联想词结果成功返回后
QObject::connect(this, &HandWirttingInput::UpdateSuggestions, this, &HandWirttingInput::fun_UpdateSuggestions);
```
槽函数的定义如下：
```cpp
//信号UpdateSuggestions()的槽函数
void HandWirttingInput::fun_UpdateSuggestions()
{
    QVector<SugResult> tmpsug = suggestions.getSugresult();

    int tmpsize = tmpsug.size();
    qDebug() << "tmpSug : " << tmpsize;

    if (tmpsize == 0)  //没有识别结果或者撤销笔划直到画布为空的边界条件
    {
        Sugbtn1->setText("");
        Sugbtn2->setText("");
        Sugbtn3->setText("");
        Sugbtn4->setText("");

    }

    if (tmpsize >= 1) Sugbtn1->setText(tmpsug[0].m_word);
    if (tmpsize >= 2) Sugbtn2->setText(tmpsug[1].m_word);
    if (tmpsize >= 3) Sugbtn3->setText(tmpsug[2].m_word);
    if (tmpsize >= 4) Sugbtn4->setText(tmpsug[3].m_word);

}
```
为什么联想词的搜索要加上这么多的判断条件？，因为我们无法确定返回的数据究竟又多少个，这个api里面没有说明统一的标准，我也测试过了，有时候可能返回十几个检索结果，有时又一个也没有，所以为了避免数组越界而导致的程序崩溃，判断条件应该更细致一点。

按下按钮期望直接将结果输入到编辑框，同时还希望能够自动清空所有结果然后为下一次识别做准备，首先需要链接到信号与槽：
```cpp
//联想词按钮槽链接
QObject::connect(Sugbtn1, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn1Clicked);
QObject::connect(Sugbtn2, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn2Clicked);
QObject::connect(Sugbtn3, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn3Clicked);
QObject::connect(Sugbtn4, &QPushButton::clicked, this, &HandWirttingInput::Sugbtn4Clicked);
```
```cpp
//联想词按钮被按下
//无论是候选词还是联想词的按钮，只要被按下，就代表用户认可当前识别结果，要清空所有按钮和画布
void HandWirttingInput::Sugbtn1Clicked()
{
    qDebug() << "Sugbtn1Clicked";

    textEdit->insertPlainText(Sugbtn1->text()); //输入按钮文本

    //清空候选框以及书写墨迹，准备下一次识别
    rewriteBtn->click();  //手动发出信号，直接转到重写的槽函数
}
```

完善退一笔功能，前面讲述了如何做到在退一笔的时候也实时识别，加入了联想词的候选框之后，也应该在退一笔的时候做到实时联想。

在删除笔划之后，会受到来自识别器的完成删除的信号，然后会执行槽函数更新识别的结果，在里面也需要对识别结果重新联想识别，所以只需要加上`emit ReadySuggest()`，请求重新查询即可。
```cpp
void HandWirttingInput::deltUpdate()
{
    tempRes.clear(); //清空上一次识别的结果
    inputs.RecogData(tempRes);

    qDebug() << tempRes.size();

    //删除最后一笔时，由于删除之后自动识别，此时画布上面什么也没有，那么结果数组temRes里面是没有任何元素的，于是访问元素下标时不合法的
    //下面的if做一个特判
    if (tempRes.size() >= 5)
    {
        btn1->setText(QString::fromUtf8(QByteArray(tempRes[0].res)));
        btn2->setText(QString::fromUtf8(QByteArray(tempRes[1].res)));
        btn3->setText(QString::fromUtf8(QByteArray(tempRes[2].res)));
        btn4->setText(QString::fromUtf8(QByteArray(tempRes[3].res)));
        btn5->setText(QString::fromUtf8(QByteArray(tempRes[4].res)));
    }
    else   //画布为空的时候
    {
        btn1->setText("");
        btn2->setText("");
        btn3->setText("");
        btn4->setText("");
        btn5->setText("");
    }

    emit ReadySuggest();

    qDebug() << "After Delete, the results has been UPDATE.";
}
```

至此联想词查询的功能就基本实现了。


## 关于TSF框架

这真的算是我的一个遗憾了，我个人是非常想实现的，但是因为之前从来没有接触过windows编程，学校里面讲授操作系统只是以linux为例子讲的一些进程同步与互斥的问题，很多更深层次的东西我一时半会理解不了。

网上能够找的资料都很零散，只通过查看资料也不能在我的脑海里搭建出一个框架，后面尝试去写的时候就出了很多问题，而且找不到很好的项目给我学习这个框架，碰到问题了也很难找到能给我提供解决思路的博客。

我不能够很好地梳理这个框架逻辑，官方文档我也试着去看了，但是还是有很多东西无法理解。然后我就去找`github`上面找微软官方的示例`SampleIME` ，很遗憾的是程序支离破碎的，而且貌似找不到程序的入口。

官方的示例似乎是一个DLL动态库，提供了一些接口由操作系统调用，然后注册输入法。单它是一个简单的拼音输入法的实现，手写输入法是需要界面的，怎么去实现和兼容呢？示例里面大大小小的c++文件有五六十个，我就想着要不我就实现几个对我有用的部分框架，但是当我试着去分析文件与文件之间的关系的时候，我越来越搞不清哪些是需要我亲自实现的，而哪些不是。当我尝试摘出几个文件的时候，他们会依赖于其他文件，其他文件又会对另外的文件有所依赖。我尝试去百度，去AI，都没有看到能很好梳理逻辑的回答。

我写程序的时候喜欢想好了再写，如果一开始我无法梳理出很清晰的逻辑，我写代码的时候会很不自信，debug的时候也会很难受。于是当我无法在短时间内理解这个框架的时候，问题就来了。

后来我找了一个博客[基于TSF框架的输入法注册流程分析_输入法 tsf 实现-CSDN博客](https://blog.csdn.net/yang1fei2/article/details/118977318)。他似乎详细介绍了应该如何去注册输入法，我就跟着做，结果是碰到了一大堆报错。这个文章里面说了要自定义COM接口，然后调用。可是我不理解怎么去调用，百度了一下都说操作系统会自己调用，只需要提供入口就好了。可是让我想不明白的是，我的程序是有main函数的呀，不能算作一个动态库。从main函数开始，之后的所有行为我都设计好了，又是怎么能只定义一个接口，然后操作系统就能够直接注册了呢？

我实在想不明白，看来寒假的时候可以学一学windows编程的基础了，操作系统都是类似的，学会了一个的编程基础，以后碰到类似的问题也不会像现在这样一头雾水了。

最后就是把这部分砍掉了，真的非常遗憾。



## 修复测试过程中遇到的bug

1. 按钮颜色的更新问题。如果不设置按钮的初始颜色的话，在最初的时候按钮的颜色可能会因为设备的问题而不一样，所以为了更好的用户体验，将所有按钮颜色都设置一个初始值。
2. 由于书写途中调用设置窗口或者符号列表窗口会导致部分墨迹隐形，虽然不太了解造成这个现象的原因，但是可以通过更新画布来解决这个问题。

以字符按钮为例子：
```cpp
//处理字符按钮
void HandWirttingInput::open_closeCharacterList() //单击打开窗口，再次点击关闭窗口
{
    if (chaListWindow == nullptr)
    {
        //......其他逻辑
    }
    else
    {
        if (chaListWindow->isVisible()) 
        {
             //......其他逻辑
            
            //新增的逻辑
            //隐藏窗口的时候要更新一下画布，这样就能较好地避免墨迹隐形的情况
            WId hshow = writeZone->winId(); //获取手写区域句柄
            HRESULT hr = InvalidateRect(reinterpret_cast<HWND>(hshow), NULL, TRUE);  //刷新手写区域

            if (FAILED(hr))
            {
                qDebug() << "InvalidateRect(hwnd, NULL, TRUE)";
                return;
            }

        }
        else 
        {
             //......其他逻辑
        }
    }


}

```

按下按钮之后，弹窗会自动关闭，也要更新画布：
```cpp
//接收来自字符串窗口的信号，并处理
void HandWirttingInput::inputCharButton(const QString& btntext)
{
   //......其他逻辑
    
    //隐藏窗口的时候要更新一下画布，这样就能较好地避免墨迹隐形的情况
    WId hshow = writeZone->winId(); //获取手写区域句柄
    HRESULT hr = InvalidateRect(reinterpret_cast<HWND>(hshow), NULL, TRUE);  //刷新手写区域

    if (FAILED(hr))
    {
        qDebug() << "InvalidateRect(hwnd, NULL, TRUE)";
        return;
    }
}
```


## 后续测试以及打包

打包是按照老师的步骤打包的：
[智能输入法大作业提交说明](https://365.kdocs.cn/l/caFEaeLmmgnw)

找了几个好朋友做测试，目前情况良好，没有发现什么问题。
发现了在使用符号列表或者弹窗时墨迹隐形的情况，还有按钮颜色的问题，目前已经修复。






## 参考资料

1.
[QT集成Windows手写输入法_win触控输入法集成到程序-CSDN博客](https://blog.csdn.net/oBoLuoChuiXue12/article/details/109632780?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-5-109632780-blog-103733342.235)

2.
[张利利/Windows手写输入法](https://gitee.com/ll.zhangll/windows_handwriting)

3.
[IInkRecognizerContext：：BackgroundRecognize (msinkaut.h) - Win32 apps | Microsoft Learn](https://learn.microsoft.com/zh-cn/windows/win32/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize)

4.
[Qt开发 | Qt界面布局 | 水平布局 | 竖直布局 | 栅格布局 | 分裂器布局 | setLayout使用 | 添加右键菜单 | 布局切换与布局删除重构_qt horizontallayout-CSDN博客](https://blog.csdn.net/zwcslj/article/details/139956054?ops_request_misc=%257B%2522request%255Fid%2522%253A%252229c9657c079dda521e67dcb2220a3369%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=29c9657c079dda521e67dcb2220a3369&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-139956054-null-null.142^v100^pc_search_result_base6&utm_term=Qt%E6%89%8B%E5%86%99%E4%BB%A3%E7%A0%81%E6%B7%BB%E5%8A%A0%E5%B8%83%E5%B1%80&spm=1018.2226.3001.4187)

5.
《Qt官方文档》

6.
《Qt5.10 GUI完全参考手册》2018-8-18(第一版) 黄勇著


## 后记

一转眼就到了最后一次大作业提交的时间了，这段时间的培训让我学到了很多东西，看到了很多在学校里面看不到的方法，也打开了视野。非常感谢金山老师们的教诲。没有这次培训，我不可能一下子学到这么多扩展知识。

虽然这段时间非常幸苦非常累，但是每处理好一个bug之后带来的成就感是无可比拟的。虽然课堂上经常听不懂，但是课下去复习然后写完练习之后就能了解到一个大概。

非常感谢自己能够坚持到最后，一路走来，幸苦了。








