/******************                                                          
	SHFE data import js                                                       
	change data file to sql .                                                  
***********************/                                                     
UltraEdit.activeDocument.findReplace.mode = 0; //only finding in current file
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete head
var lines = 0;
UltraEdit.activeDocument.gotoPos(0);
while(lines < 99) {
		UltraEdit.activeDocument.deleteLine();
		lines = lines +1;	
}

UltraEdit.activeDocument.gotoLine(5137,0);
lines = 0;
while(lines < 440) {
		UltraEdit.activeDocument.deleteLine();
		lines = lines +1;	
}

//delete blank
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("<td class='a1' align='center'>","");
UltraEdit.activeDocument.findReplace.replace("<td class='a1' align='right'>","");
UltraEdit.activeDocument.findReplace.replace("\r\n","");
UltraEdit.activeDocument.findReplace.replace("</td>",",");
UltraEdit.activeDocument.findReplace.replace("</tr>",");\r\n");
UltraEdit.activeDocument.findReplace.replace(" ","");
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete \x09>'
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.replace("\x09","");
UltraEdit.activeDocument.findReplace.regExp = false;
UltraEdit.activeDocument.findReplace.replaceAll = false;

//delete С��
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.find(",,,,,,,,,");
while(UltraEdit.activeDocument.isFound()) {
	UltraEdit.activeDocument.deleteLine();
	UltraEdit.activeDocument.findReplace.find(",,,,,,,,,");
}

//delete <td colspan='14'
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.find("<tdcolspan='14'");
while(UltraEdit.activeDocument.isFound()) {
	UltraEdit.activeDocument.deleteLine();
	UltraEdit.activeDocument.findReplace.find("<tdcolspan='14'");
}

//replace instrument name
UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace(",,",",0,");
UltraEdit.activeDocument.findReplace.replace(",,",",0,");
UltraEdit.activeDocument.findReplace.replace(",)",")");
UltraEdit.activeDocument.findReplace.replace("����","'AG'");
UltraEdit.activeDocument.findReplace.replace("��","'AL'");
UltraEdit.activeDocument.findReplace.replace("�ƽ�","'AU'");
UltraEdit.activeDocument.findReplace.replace("ͭ","'CU'");
UltraEdit.activeDocument.findReplace.replace("ȼ����","'FU'");
UltraEdit.activeDocument.findReplace.replace("Ǧ","PB");
UltraEdit.activeDocument.findReplace.replace("���Ƹ�","'RB'");
UltraEdit.activeDocument.findReplace.replace("��Ȼ��","'RU'");
UltraEdit.activeDocument.findReplace.replace("�߲�","'WR'");
UltraEdit.activeDocument.findReplace.replace("п","'ZN'");
UltraEdit.activeDocument.findReplace.replaceAll = false;

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.regExp = true;
UltraEdit.activeDocument.findReplace.replace("[\xBB]{1}[\xC6]{1}[\xBD]{1}[\xF0]{1}","'AU'");
UltraEdit.activeDocument.findReplace.replace("[\xCD]{1}[\xAD]{1}","'CU'");
UltraEdit.activeDocument.findReplace.replace("[\xC7]{1}[\xA6]{1}","'PB'");
UltraEdit.activeDocument.findReplace.replace("[\xD0]{1}[\xBF]{1}","'ZN'");
UltraEdit.activeDocument.findReplace.regExp = false;


//append the  instrument name if line have not.
UltraEdit.clearClipboard();
UltraEdit.activeDocument.gotoPos(0);
var lineNum = 0;
UltraEdit.activeDocument.gotoLine(lineNum,21);
while(UltraEdit.activeDocument.isEof() == false) {
	
	if (UltraEdit.activeDocument.isChar(",")) {
		UltraEdit.activeDocument.paste();
	} else {
		UltraEdit.activeDocument.gotoLineSelect(lineNum,25);
		UltraEdit.activeDocument.copy();	
	}
  
  lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,21);
}

//instrument '
UltraEdit.activeDocument.gotoPos(0);
var lineNum = 0;
UltraEdit.activeDocument.gotoLine(lineNum,26);
while(UltraEdit.activeDocument.isEof() == false) {
	UltraEdit.activeDocument.write("'");
	UltraEdit.activeDocument.gotoLine(lineNum,31);
  UltraEdit.activeDocument.write("'");
  lineNum = lineNum + 1;
  UltraEdit.activeDocument.gotoLine(lineNum,26);
}

//sql
var filePath = UltraEdit.activeDocument.path;
var indexLast = filePath.lastIndexOf("\\");
var fileName = "INSERT INTO Shfe_Marketdata (Tradingday, Productid, Deliverydate, Presettlementprice, Openprice, Highestprice, Lowestprice, Closeprice, Settlementprice, Updownprice1, Updownprice2, Volume, Position, Positionchg) VALUES ('"+filePath.substring(indexLast+1,indexLast+9)+"',";

UltraEdit.activeDocument.gotoPos(0);
UltraEdit.activeDocument.findReplace.replaceAll = true;
UltraEdit.activeDocument.findReplace.replace("<trclass='bgcolorB'>",fileName);
UltraEdit.activeDocument.findReplace.replaceAll = false;