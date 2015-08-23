/******************                                                          
	DCE data import js                                                       
	change data file to sql .                                                  
***********************/   
UltraEdit.activeDocument.findReplace.mode = 0; //only finding in current file
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete head
var lines = 0;
UltraEdit.activeDocument.gotoPos(0);
while(lines < 4) {
		UltraEdit.activeDocument.deleteLine();
		lines = lines +1;	
}

//delete Ð¡¼Æ
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.find("[\xD0]{1}[\xA1]{1}[\xBC]{1}[\xC6]{1}");
while(UltraEdit.activeDocument.isFound()) {
	UltraEdit.activeDocument.deleteLine();
	UltraEdit.activeDocument.findReplace.find("[\xD0]{1}[\xA1]{1}[\xBC]{1}[\xC6]{1}");
}
UltraEdit.activeDocument.findReplace.regExp = false;

//delete ×Ü¼Æ
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.find("[\xD7]{1}[\xDC]{1}[\xBC]{1}[\xC6]{1}");
while(UltraEdit.activeDocument.isFound()) {
	UltraEdit.activeDocument.deleteLine();
	UltraEdit.activeDocument.findReplace.find("[\xD7]{1}[\xDC]{1}[\xBC]{1}[\xC6]{1}");
}
UltraEdit.activeDocument.findReplace.regExp = false;


//replace instrument name
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("¶¹¶þ","'B','");
UltraEdit.activeDocument.findReplace.replace("ÓñÃ×","'C','");
UltraEdit.activeDocument.findReplace.replace("¾ÛÒÒÏ©","'L','");
UltraEdit.activeDocument.findReplace.replace("¶¹ÆÉ","'M','");
UltraEdit.activeDocument.findReplace.replace("×ØéµÓÍ","'P','");
UltraEdit.activeDocument.findReplace.replace("¾ÛÂÈÒÒÏ©","'V','");
UltraEdit.activeDocument.findReplace.replace("¶¹ÓÍ","'Y','");

UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.replace("[\xB6]{1}[\xB9]{1}[\xD2]{1}[\xBB]{1}","'A','");
UltraEdit.activeDocument.findReplace.replace("[\xBD]{1}[\xB9]{1}[\xCC]{1}[\xBF]{1}","'J','");
UltraEdit.activeDocument.findReplace.regExp = false;

UltraEdit.activeDocument.findReplace.replace("\r\n",");\r\n");

UltraEdit.activeDocument.findReplace.replaceAll = false;

//insert ,
UltraEdit.activeDocument.gotoPos(0);
var lineNum = 1;
UltraEdit.activeDocument.gotoLine(lineNum,32);
while(UltraEdit.activeDocument.isEof() == false) {
	UltraEdit.activeDocument.write("',");
	
	UltraEdit.activeDocument.gotoLine(lineNum,45);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,57);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,69);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,81);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,93);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,105);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,117);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,129);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,144);
  UltraEdit.activeDocument.write(",");

	UltraEdit.activeDocument.gotoLine(lineNum,159);
  UltraEdit.activeDocument.write(",");
  
  UltraEdit.activeDocument.gotoLine(lineNum,174);
  UltraEdit.activeDocument.write(",");
  
  lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,32);
}


UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace(" ","");
UltraEdit.activeDocument.findReplace.replace("-,","0,");
UltraEdit.activeDocument.findReplace.replaceAll = false;

//insert ,
UltraEdit.activeDocument.gotoPos(0);
var lineNum = 1;

var filePath = UltraEdit.activeDocument.path;
var indexLast = filePath.lastIndexOf("\\");
var fileName = "INSERT INTO Dce_Marketdata (Tradingday, Productid, Deliverydate, Openprice, Highestprice, Lowestprice, Closeprice, Presettlementprice, Settlementprice, Updownprice1, Updownprice2, Volume, Position, Positionchg, Turnover) VALUES ('"+filePath.substring(indexLast+1,indexLast+9)+"',";

UltraEdit.activeDocument.gotoLine(lineNum,1);
while(UltraEdit.activeDocument.isEof() == false) {
	UltraEdit.activeDocument.write(fileName);
  lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,1);
}
