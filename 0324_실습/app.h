//app.h

#pragma once

//최초 한번 실행되는 문장들(함수들)
void app_init();

//프로그램 동작과정에서 반복실행되는 문장들(함수들)
void app_run();

//프로그램 종료시 한번 실행되는 문장들(함수들)
void app_exit();

void logo();
char menuprint();
void ending();
