/////////////////////////////////////////////////////////////////////////
///@copyright All Right Reserved.(C) 2010-2012 ZYSystem by Ziumsoft.
///@file CConfigXml.cpp
///@brief 程序化交易的配置文件读取器实现
///@author 张弛
///@date 20110329
/////////////////////////////////////////////////////////////////////////
#include "CConfigXml.h"

#ifndef CConfigXml_CPP_
#define CConfigXml_CPP_

using namespace ZYSystem;

void CConfigXml::getServerId(TConnectionID conn_id_in){
	elementCharValue("/config/server_id",conn_id_in);
}

void CConfigXml::getInstruments(TInstrumentIDs instruments_in){
	elementCharValue("/config/instruments",instruments_in);
}

void CConfigXml::getLogConfig(SLogConfig* logConfig_in){
	logConfig_in->LogOutputType = (TLogOutputType) elementIntValue("/config/log/log_type");
	logConfig_in->LogLevel = (TLogLevel) elementIntValue("/config/log/log_level");
	elementCharValue("/config/log/log_path",logConfig_in->LogPath);
}

void CConfigXml::getDataPath(TPath data_path_in){
	elementCharValue("/config/data_path",data_path_in);
}

TVolume CConfigXml::countInvestor()
{
	return  elementIntValue("count(/config/investors/investor)");
}

TVolume CConfigXml::countConnConfig()
{
	return elementIntValue("count(/config/connections/connection)");
}

TVolume CConfigXml::countModel()
{
	return elementIntValue("count(/config/models/model)");
}

TID CConfigXml::getInvestor(TID id,SInvestor* investor)
{
	if  (id > countInvestor()) {
		return -1;
	}
	
	char* tmpInvestorNode = new TXPath;
	sprintf(tmpInvestorNode,"/config/investors/investor[position()=%d]",id);
	TiXmlNode* investorNode = TinyXPath::XNp_xpath_node(dom.RootElement(), tmpInvestorNode);

	if(investorNode != NULL){
		elementCharValue("//investor/investor_id",investor->InvestorID,investorNode);
		elementCharValue("//investor/investor_password",investor->InvestorPassword,investorNode);	
		elementCharValue("//investor/broker_id",investor->BrokerID,investorNode);
		elementCharValue("//investor/account_id",investor->AccountID,investorNode);
		elementCharValue("//investor/account_password",investor->AccountPassword,investorNode);

		LOG_SInvestor(investor);
	} else {
		return -1;
	}

	return SUCCESS;
}

TID CConfigXml::getConnConfig(TConnectionID id,SMarketDataProvider* config)
{
	char *tmp = new TXPath;
	sprintf(tmp,"/config/connections/connection/conn_id[self::text() =  '%s']",id);
	TiXmlNode* connNode = TinyXPath::XNp_xpath_node(dom.RootElement(), tmp)->Parent();

	if(connNode != NULL){
		elementCharValue("//conn_id",config->ConnectionID,connNode);	
		elementCharValue("//md_url",config->Md_url,connNode);
		elementCharValue("//td_url",config->Td_url,connNode);
		config->ConnectionType =(TMarketDataType) elementIntValue("//conn_type",connNode);
		elementCharValue("//investor_id",config->InvestorID,connNode);

		LOG_SMarketDataProvider(config);
	} else {
		return -1;
	}
	
	return SUCCESS;
}

TID CConfigXml::getModel(TID id,SModelConfigA* model)
{
	if  (id > this->countModel()) {
		return -1;
	}

	char *tmp = new TXPath;
	sprintf(tmp,"/config/models/model[position()=%d]",id);
	TiXmlNode* connNode = TinyXPath::XNp_xpath_node(dom.RootElement(), tmp);

	if(connNode != NULL){
		elementCharValue("//model/investor_id",model->InvestorID,connNode);	
		model->ModelType =(TModelType) elementIntValue("//model/model_type",connNode);
		model->CalculateCycle = elementIntValue("//model/time_cycle",connNode);
		
		//路径会在dataroute中被重设
		getDataPath(model->DataPath);

		model->Idx_k = elementDoubleValue("//model/last_Idx_k",connNode);
		model->Idx_d = elementDoubleValue("//model/last_Idx_d",connNode);
		model->Idx_j = elementDoubleValue("//model/last_Idx_j",connNode);
		model->Idx_diff = elementDoubleValue("//model/last_Idx_diff",connNode);
		model->Idx_dea = elementDoubleValue("//model/last_Idx_dea",connNode);
		model->Idx_bar = elementDoubleValue("//model/last_Idx_bar",connNode);

		model->MAX_k = elementDoubleValue("//model/MAX_k",connNode);
		model->MAX_d = elementDoubleValue("//model/MAX_d",connNode);
		model->MAX_j = elementDoubleValue("//model/MAX_j",connNode);
		model->MAX_diff = elementDoubleValue("//model/MAX_diff",connNode);
		model->MAX_dea = elementDoubleValue("//model/MAX_dea",connNode);
		model->MAX_bar = elementDoubleValue("//model/MAX_bar",connNode);

		model->MIN_k = elementDoubleValue("//model/MIN_k",connNode);
		model->MIN_d = elementDoubleValue("//model/MIN_d",connNode);
		model->MIN_j = elementDoubleValue("//model/MIN_j",connNode);
		model->MIN_diff = elementDoubleValue("//model/MIN_diff",connNode);
		model->MIN_dea = elementDoubleValue("//model/MIN_dea",connNode);
		model->MIN_bar = elementDoubleValue("//model/MIN_bar",connNode);

		LOG_SModelConfigA(model);
	} else {
		return -1;
	}
	
	return SUCCESS;
}

CConfigXml::CConfigXml(const TFile configFile):CXML(configFile){
}

CConfigXml::~CConfigXml(void)
{
}

TRunModel CConfigXml::getRunModel(){
	return (TRunModel) elementIntValue("//runModel");
}

TID CConfigXml::getRiskControler(SRiskControler* riskControler) {
	riskControler->FullPrice = elementDoubleValue("//riskControler/fullPrice",dom.RootElement());
	riskControler->StopLossPrice = elementDoubleValue("//riskControler/stopLossPrice",dom.RootElement());

	LOG_SRiskControler(riskControler);

	return SUCCESS;
}

#endif //CConfigXml_CPP