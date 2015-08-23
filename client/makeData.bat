cls
del/Q .\TEMP\*
copy ..\server\target\DATA\%1\*.csv .\TEMP\

.\SaxonHE9.3N\Transform -o:.\TEMP\oneMinute.xml -it:main -xsl:.\toHTML5\csvToXml.xslt pathToCSV=file:///E:/zysystem/client/TEMP/oneMinute.csv
.\SaxonHE9.3N\Transform -o:.\TEMP\MACD.xml -it:main -xsl:.\toHTML5\csvToXml.xslt pathToCSV=file:///E:/zysystem/client/TEMP/MACD.csv
.\SaxonHE9.3N\Transform -o:.\TEMP\KDJ.xml -it:main -xsl:.\toHTML5\csvToXml.xslt pathToCSV=file:///E:/zysystem/client/TEMP/KDJ.csv
.\SaxonHE9.3N\Transform -o:.\TEMP\Order.xml -it:main -xsl:.\toHTML5\csvToXml.xslt pathToCSV=file:///E:/zysystem/client/TEMP/Order.csv

.\SaxonHE9.3N\Transform -o:.\TEMP\oneMinute.txt -xsl:.\toHTML5\makeData2K.xslt -s:.\TEMP\oneMinute.xml
.\SaxonHE9.3N\Transform -o:.\TEMP\Order.txt -xsl:.\toHTML5\order.xslt -s:.\TEMP\Order.xml

del/Q .\DATA\*
copy .\TEMP\*.txt .\DATA\