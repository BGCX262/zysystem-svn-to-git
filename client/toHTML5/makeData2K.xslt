<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:fn="fn"
  xmlns:xs="http://www.w3.org/2001/XMLSchema"
  version="2.0" exclude-result-prefixes="xs fn">
  <xsl:output method="text" indent="no"/>
  <xsl:variable name="k" select="document('..\TEMP\oneMinute.xml')"/>
  <xsl:variable name="macd" select="document('..\TEMP\MACD.xml')"/>
  <xsl:variable name="kdj" select="document('..\TEMP\KDJ.xml')"/>
  <xsl:template match="/" name="kLine">
  {
      "layout":"x1",
      "graphset" : [{
      "type" : "stock",
      "guide":{"shared":true},
      "plot":{
            "rules" : [{
                "rule" : "%v3 &lt; %v0",
		        "background-color": "#00ff00"
	        },{
		        "rule" : "%v3 &gt; %v0",
		        "background-color": "#ff0000"
            }]
        },    
        "plotarea" : {"width" : 750,"height" : 160,"margin-top" : 10,"margin-left" : 60},
        "scale-x" : {
            "values" :[<xsl:for-each select="$k/root/row">"<xsl:value-of select="substring(elem[@name='UpdateTime'],1,5)" />",</xsl:for-each>]
        },
        "series" : [{
            "values" :[
                <xsl:for-each select="$k/root/row">
                [<xsl:value-of select="elem[@name='OpenPrice']" />,<xsl:value-of select="elem[@name='HighestPrice']" />,<xsl:value-of select="elem[@name='LowestPrice']" />,<xsl:value-of select="elem[@name='ClosePrice']" />],
                </xsl:for-each>]
        }]
    },{
        "type" : "line",
        "guide":{ "shared":true  },
        "plotarea" : {"width" : 750,"height" : 160,"margin-top" : 10,"margin-left" : 60},
        "scale-x" : {
            "values" :[<xsl:for-each select="$kdj/root/row">"<xsl:value-of select="substring(elem[@name='UpdateTime'],1,5)" />",</xsl:for-each>]
        },
        "series" : [
            {"values" :[<xsl:for-each select="$kdj/root/row"><xsl:value-of select="elem[@name='Idx_k']" />,</xsl:for-each>]},
            {"values" :[<xsl:for-each select="$kdj/root/row"><xsl:value-of select="elem[@name='Idx_d']" />,</xsl:for-each>]}
        ]
    },{
        "type" : "line",
        "guide":{"shared":true},
        "plotarea" : {"width" : 750,"height" : 160,"margin-top" : 10,"margin-left" : 60},
        "scale-x" : {
            "values" :[<xsl:for-each select="$macd/root/row">"<xsl:value-of select="substring(elem[@name='UpdateTime'],1,5)" />",</xsl:for-each>]
        },
        "series" : [
            {"values" :[<xsl:for-each select="$macd/root/row"><xsl:value-of select="elem[@name='Idx_diff']" />,</xsl:for-each>]},
            {"values" :[<xsl:for-each select="$macd/root/row"><xsl:value-of select="elem[@name='Idx_dea']" />,</xsl:for-each>]}
        ]
  }]
}
</xsl:template>
</xsl:stylesheet>