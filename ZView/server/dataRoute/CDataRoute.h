
/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CDataRoute.h
///@brief 数据路由声明,负责将接收到的行情数据转发到计算器和行情落地到文件,单例模式
///       其实就是一个系统内部运行的消息总线，沟通各个部件
///@author xslt模型代码转换工具
///@date 2013-06-21T07:28:13.962Z
/////////////////////////////////////////////////////////////////////////
#include "CTPackageFactory.h"
#include "MsgQueue.h"

#ifndef CDATAROUTE_H_
#define CDATAROUTE_H_

namespace ZYSystem {

	class CDataRoute
	{
		private:    
   
      ///@brief 日志信息包转发器
  		boost::signals2::signal<TID (SLog*)> sig_SLog;
   
      ///@brief 行情提供者包转发器
  		boost::signals2::signal<TID (SMarketDataProvider*)> sig_SMarketDataProvider;
   
      ///@brief 投资者包转发器
  		boost::signals2::signal<TID (SInvestor*)> sig_SInvestor;
   
      ///@brief 行情包转发器
  		boost::signals2::signal<TID (SMarketData*)> sig_SMarketData;
   
      ///@brief KDJ指标包转发器
  		boost::signals2::signal<TID (SKDJ*)> sig_SKDJ;
   
      ///@brief MACD指标包转发器
  		boost::signals2::signal<TID (SMACD*)> sig_SMACD;
   
      ///@brief 计算模型A配置包转发器
  		boost::signals2::signal<TID (SModelConfigA*)> sig_SModelConfigA;

      COrderReqWriter* OrderReqW;
               
      ///@brief 报单请求包转发器
  		boost::signals2::signal<TID (SOrderReq*)> sig_SOrderReq;

      CTradeWriter* TradeW;
               
      ///@brief 成交包转发器
  		boost::signals2::signal<TID (STrade*)> sig_STrade;
   
      ///@brief 盘中仓位包转发器
  		boost::signals2::signal<TID (SRealPosition*)> sig_SRealPosition;
   
      ///@brief 盘中资金包转发器
  		boost::signals2::signal<TID (SRealFund*)> sig_SRealFund;
   
      ///@brief 订阅的合约包包转发器
  		boost::signals2::signal<TID (SSubInstrument*)> sig_SSubInstrument;

      CSingnalWriter* SingnalW;
               
      ///@brief 交易信号包转发器
  		boost::signals2::signal<TID (SSingnal*)> sig_SSingnal;
   
      ///@brief 合约包转发器
  		boost::signals2::signal<TID (SInstrument*)> sig_SInstrument;
   
      ///@brief 风险管理器包转发器
  		boost::signals2::signal<TID (SRiskControler*)> sig_SRiskControler;
   
      ///@brief 出入金包转发器
  		boost::signals2::signal<TID (SMoneyChange*)> sig_SMoneyChange;
   
      ///@brief 新交易日包转发器
  		boost::signals2::signal<TID (SNewTradingDay*)> sig_SNewTradingDay;

      COrderRspWriter* OrderRspW;
               
      ///@brief 报单响应包转发器
  		boost::signals2::signal<TID (SOrderRsp*)> sig_SOrderRsp;
   
      ///@brief 合约保证金率包转发器
  		boost::signals2::signal<TID (SMarginRate*)> sig_SMarginRate;
   
      ///@brief 合约手续费率包转发器
  		boost::signals2::signal<TID (SFeeRate*)> sig_SFeeRate;
   
      ///@brief 日志配置信息包转发器
  		boost::signals2::signal<TID (SLogConfig*)> sig_SLogConfig;

			///@brief 转发队列
			CMsgQueue* queue;
      
      ///@brief 连接器
      boost::function0<void> connectConnector;

      ///@brief 行情转发队列
			CMsgQueue* MDqueue;

			///@brief 行情路由实例
			static CDataRoute* instance;

			///@brief 封包、解包
			CTPackageFactory packageFactory;
			
			CDataRoute(void);
		public:
			///@brief 发包接口 
			///@param in 发给数据路由包
			void send(CTPackage* in);
      
      ///@brief 设置用于启动的connnection
      ///@param f 函数
  		void setConnector(boost::function0<void> connectConnector_in);


      ///@brief 订阅日志信息
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SLog*)> f);

      ///@brief 订阅行情提供者
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SMarketDataProvider*)> f);

      ///@brief 订阅投资者
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SInvestor*)> f);

      ///@brief 订阅行情
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SMarketData*)> f);

      ///@brief 订阅KDJ指标
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SKDJ*)> f);

      ///@brief 订阅MACD指标
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SMACD*)> f);

      ///@brief 订阅计算模型A配置
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SModelConfigA*)> f);

      ///@brief 订阅报单请求
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SOrderReq*)> f);

      ///@brief 订阅成交
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (STrade*)> f);

      ///@brief 订阅盘中仓位
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SRealPosition*)> f);

      ///@brief 订阅盘中资金
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SRealFund*)> f);

      ///@brief 订阅订阅的合约包
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SSubInstrument*)> f);

      ///@brief 订阅交易信号
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SSingnal*)> f);

      ///@brief 订阅合约
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SInstrument*)> f);

      ///@brief 订阅风险管理器
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SRiskControler*)> f);

      ///@brief 订阅出入金
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SMoneyChange*)> f);

      ///@brief 订阅新交易日
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SNewTradingDay*)> f);

      ///@brief 订阅报单响应
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SOrderRsp*)> f);

      ///@brief 订阅合约保证金率
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SMarginRate*)> f);

      ///@brief 订阅合约手续费率
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SFeeRate*)> f);

      ///@brief 订阅日志配置信息
      ///@param f 订阅的方法
  		void subscribe(boost::function<TID (SLogConfig*)> f);

               
			///@brief 发包接口 
			///@param in 发给数据路由包
			///@param f 订阅的方法
			void startup();

			///@brief 获取数据路由实例
			///@return 数据路由
			static CDataRoute* getInstance();

			///@brief CDataRoute析构
      ~CDataRoute(void);
	};
}
#endif //CDATAROUTE_H_
		