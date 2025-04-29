cmake_minimum_required(VERSION 3.10)

PROJECT(ObserverModel)

add_executable(${PROJECT_NAME} 
	main.cpp
	Iobserver.h
	interphone.h
	phone.h
	Isubject.h
	radio.h
)
