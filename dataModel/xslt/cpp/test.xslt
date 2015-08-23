<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="2.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:xs="http://www.w3.org/2001/XMLSchema"
	xmlns:fn="http://www.w3.org/2005/xpath-functions">
    
    <xsl:output method="text" indent="no" encoding="utf-8" byte-order-mark="yes"/>
    <xsl:template match="*">
        <xsl:result-document encoding="GBK" method="text" href="./generate/x.h">
            <xsl:value-of select="/config/connections/connection/conn_id/text()[contains(., '2')]"/>
        </xsl:result-document>
    </xsl:template>
</xsl:stylesheet>
