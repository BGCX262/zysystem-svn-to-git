<xsl:stylesheet
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:fn="fn"
  xmlns:xs="http://www.w3.org/2001/XMLSchema"
  version="2.0" exclude-result-prefixes="xs fn">
    <xsl:output method="text" indent="no"/>
    <xsl:variable name="order" select="document('..\TEMP\Order.xml')"/>
    <xsl:template match="/" name="order">
    [
        <xsl:for-each select="$order/root/row">
        {"OrderTime":"<xsl:value-of select="elem[@name='OrderTime']" />",
         "InstrumentID":"<xsl:value-of select="elem[@name='InstrumentID']" />",
         "OffsetFlag":"<xsl:if test="elem[@name='OffsetFlag'] = 0">开</xsl:if><xsl:if test="elem[@name='OffsetFlag']!= 0">平</xsl:if>",
         "Direction":"<xsl:if test="elem[@name='Direction'] = 0">买</xsl:if><xsl:if test="elem[@name='Direction'] = 1">卖</xsl:if>",
         "Price":"<xsl:value-of select="elem[@name='Price']" />",
         "Volume":"<xsl:value-of select="elem[@name='Volume']" />"},
        </xsl:for-each>
    ]     
    </xsl:template>
</xsl:stylesheet>