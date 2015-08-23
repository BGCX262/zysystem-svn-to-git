/******************                                                          
	CZCE data import js                                                       
	change data file to sql .                                                  
***********************/                                                     
UltraEdit.activeDocument.findReplace.mode = 0; //only finding in current file
UltraEdit.activeDocument.findReplace.replaceAll = false;


//delete title
UltraEdit.activeDocument.gotoPos(0);  
UltraEdit.activeDocument.deleteLine();

//delete Ð¡¼Æ
UltraEdit.activeDocument.findReplace.find(",,,,");
while(UltraEdit.activeDocument.isFound()) {
	UltraEdit.activeDocument.deleteLine();
	UltraEdit.activeDocument.findReplace.find(",,,,");
}

//add "'"
UltraEdit.activeDocument.gotoPos(0);
var lineNum = 1;
UltraEdit.activeDocument.gotoLine(1,6);
while(UltraEdit.activeDocument.isEof() == false) {
	UltraEdit.activeDocument.write("'");
  lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,6);
}

//add tradingdate 
var filePath = UltraEdit.activeDocument.path;
var indexLast = filePath.lastIndexOf("\\");
var fileName = "INSERT INTO Czce_Marketdata (Tradingday, Instrumentid,Presettlementprice,Openprice,Highestprice,Lowestprice,Closeprice,Settlementprice,Updownprice1,Updownprice2,Volume,Position,Positionchg,Turnover,Deliveryprice) VALUES ('"+filePath.substring(indexLast+1,indexLast+9)+"','";
UltraEdit.activeDocument.gotoPos(0);
lineNum = 1;
while(UltraEdit.activeDocument.isEof() == false) {
	UltraEdit.activeDocument.write(fileName);
	lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,1);
}

//delete blankline
UltraEdit.activeDocument.deleteLine();
UltraEdit.activeDocument.deleteLine();

//replace \r\n
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("\r\n",");\r\n");
UltraEdit.activeDocument.findReplace.replaceAll = false;

