﻿#cktrader 
#介绍
这个交易框架主要是仿照VNPY编写，支持动态加载接口，动态加载策略。
目前支持CTP交易接口
#环境搭建
1、开发环境VS2015 community
2、需要将包含文件目录指向include目录，框架无需第三方库依赖，但是框架的事件引擎，gateway，策略是相互依赖的，编译时需要指定输入库
3、CTP接口是最新版本
4、编译顺序：eventservice->tradercore->gateway->strategy->test
#计划
1、回测引擎编写
2、UI界面编写
3、其他交易接口接入
#QQ群
470226823