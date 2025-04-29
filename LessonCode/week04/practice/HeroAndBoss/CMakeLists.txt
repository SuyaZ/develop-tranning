cmake_minimum_required(VERSION 3.10)

PROJECT(HeroAndBoss)

add_executable(${PROJECT_NAME} 
	main.cpp
	IObserver.h
	Hero.h
	Isubject.h
	Dragon.h
)
