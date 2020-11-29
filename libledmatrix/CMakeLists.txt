# -*- coding:utf-8 -*-
# -*- кодировка:utf-8 -*-

SET (SUBPROJECT ledmatrix)
PROJECT (${SUBPROJECT})



SET (HEADERS
   ledmatrix.h
   cutf.h

)

SET (SOURCES
   ledmatrix.c
   cutf.c
)



SOURCE_GROUP ("Header Files" FILES ${HEADERS})
SOURCE_GROUP ("Source Files" FILES ${SOURCES})


ADD_LIBRARY(${SUBPROJECT}  ${HEADERS} ${SOURCES}   )

TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT} PUBLIC ${FULL_SOURCE_DIR} )

TARGET_LINK_LIBRARIES (${SUBPROJECT} yqnet boost_system boost_thread boost_filesystem boost_date_time )

