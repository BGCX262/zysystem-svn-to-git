/******************
	Cffex data import js
	change data file to sql .
***********************/
UltraEdit.activeDocument.findReplace.mode = 0; //only finding in current file

//delete blank
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace(" ","");
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete "<p>IF</p></da>"
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("<p>IF</p></da>","");
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete '<k>[0-9]+.[0-9]+</k>'
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.replace("<k>[0-9]+.[0-9]+</k>","");
UltraEdit.activeDocument.findReplace.regExp = false;
UltraEdit.activeDocument.findReplace.replaceAll = false;

// replace "<da>" -> "\r\n"
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("<da>","\r\n");
UltraEdit.activeDocument.findReplace.replaceAll = false;

// delete line "<?xml version="1.0"?>" 
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.deleteLine();

//delete '<k>[0-9]+.[0-9]+</k>'
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("<k>[0-9]+.[0-9]+</k>","");
UltraEdit.activeDocument.findReplace.replaceAll = false;

//make sql
UltraEdit.activeDocument.findReplace.replaceAll = true;

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("<a>","INSERT INTO cffex_marketdata(tradingday, instrumentid, openprice, highestprice, lowestprice, volume, turnover, position, closeprice, settlementprice, updownprice1, updownprice2) VALUES('");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</a><b>","','");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</b><c>","',");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</c><d>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</d><e>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</e><f>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</f><g>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</g><h>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</h><i>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</i><j>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</j><l>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</l><m>",",");

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</m>",");");

UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete blank
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replace("</marketDatas>","\r\ncommit;");