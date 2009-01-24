/***************************************************************************
  DIA_dialogFactory.cpp
  (C) 2007 Mean Fixounet@free.fr 
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>

#include "T_dialogFactory.h"
#include "ADM_default.h"
#include "DIA_factory.h"
#include "DIA_coreToolkit.h"
#include "DIA_coreUI_internal.h"

static void insertTab(uint32_t index, diaElemTabs *tab, QTabWidget *wtab);
factoryWindow::factoryWindow()     : QDialog()
 {
//     ui.setupUi(this);
     //connect( (ui.pushButton),SIGNAL(pressed()),this,SLOT(buttonPressed()));
 }


/**
    \fn qt4DiaFactoryRun(const char *title,uint32_t nb,diaElem **elems)
    \brief  Run a dialog made of nb elems, each elem being described in the **elems
    @return 0 on failure, 1 on success
*/

uint8_t qt4DiaFactoryRun(const char *title,uint32_t nb,diaElem **elems)
{
  factoryWindow dialog;
  
  ADM_assert(title);
  ADM_assert(nb);
  ADM_assert(elems);
  
  dialog.setWindowTitle(QString::fromUtf8(title));
  
  QGridLayout layout(&dialog);
  
  /* First compute the size of our window */
  int vsize=0;
  for(int i=0;i<nb;i++)
  {
    ADM_assert(elems[i]);
     vsize+=elems[i]->getSize(); 
  }

 int  v=0;
  for(int i=0;i<nb;i++)
  {
    ADM_assert(elems[i]);
     elems[i]->setMe( (void *)&dialog,&layout,v); 
     v+=elems[i]->getSize();
    
  }
   for(int i=0;i<nb;i++)
  {
    ADM_assert(elems[i]);
     elems[i]->finalize(); 
  }
  // Add buttons
   QDialogButtonBox buttonBox((QWidget *)&dialog);
    buttonBox.setStandardButtons(QDialogButtonBox::Ok
                            | QDialogButtonBox::Cancel);
     QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
     QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
     layout.addWidget(&buttonBox,vsize,0);
  // run
  dialog.setLayout(&layout);
  if(dialog.exec()==QDialog::Accepted)
  {
     for(int i=0;i<nb;i++)
     {
        ADM_assert(elems[i]);
        elems[i]->getMe(); 
    
      }
    return 1;
  }
  return 0;
  
}
/**
    \fn shortkey(const char *in)
    \brief translate gtk like accelerator (_) to QT4 like accelerator (&)
*/
const char *shortkey(const char *in)
{
 char *t=ADM_strdup(in);
 for(int i=0;i<strlen(t);i++)
 {
    if(t[i]=='_') t[i]='&'; 
 }
  return t;
}
/**
 * 	\fn qt4DiaFactoryRunTabs
 */
uint8_t qt4DiaFactoryRunTabs(const char *title,uint32_t nb,diaElemTabs **tabs)
{
    factoryWindow dialog;
  
  ADM_assert(title);
  ADM_assert(nb);
  ADM_assert(tabs);
  
  dialog.setWindowTitle(QString::fromUtf8(title));
  
  QGridLayout layout(&dialog);

  // Add tabs
  QTabWidget wtabs((QWidget *)&dialog);
  // Add buttons
   QDialogButtonBox buttonBox((QWidget *)&dialog);
    buttonBox.setStandardButtons(QDialogButtonBox::Ok
                            | QDialogButtonBox::Cancel);
     QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
     QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
     
     for(int i=0;i<nb;i++)
     {
        ADM_assert(tabs[i]);
        insertTab(i,tabs[i],&wtabs); 
    
      }
     
     layout.addWidget(&wtabs,0,0);
     layout.addWidget(&buttonBox,1,0);
  // run
  dialog.setLayout(&layout);
  if(dialog.exec()==QDialog::Accepted)
  {
      // Read tabs
       for(int tab=0;tab<nb;tab++)
     {
        ADM_assert(tabs[tab]);
        diaElemTabs *myTab=tabs[tab];
        for(int i=0;i<myTab->nbElems;i++)
        {
          myTab->dias[i]->getMe();
        }
    
      }
      return 1;
  }
  return 0;
  
}

void insertTab(uint32_t index, diaElemTabs *tab, QTabWidget *wtab)
{

  QWidget *wid=new QWidget;
  QGridLayout *layout=new QGridLayout(wid);
  QSpacerItem *spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  
  /* First compute the size of our window */
  int vsize=0;
  for(int i=0;i<tab->nbElems;i++)
  {
    ADM_assert(tab->dias[i]);
     vsize+=tab->dias[i]->getSize(); 
  }

 int  v=0;
  for(int i=0;i<tab->nbElems;i++)
  {
     ADM_assert(tab->dias[i]);
     tab->dias[i]->setMe( wid,layout,v); 
     v+=tab->dias[i]->getSize();
    
  }
  
  wtab->addTab(wid,QString::fromUtf8(tab->title));
  for(int i=0;i<tab->nbElems;i++)
  {
    tab->dias[i]->finalize(); 
  }

  layout->addItem(spacerItem, v, 0);
}

/**
 * 
 */
/**
 *  \fn gtkFactoryGetVersion
 * 	\brief returns the version this has been compiled with
 */
void      qt4FactoryGetVersion(uint32_t *maj,uint32_t *minor,uint32_t *patch)
{
	*maj=ADM_COREUI_MAJOR;
	*minor=ADM_COREUI_MINOR;
	*patch=ADM_COREUI_PATCH;
	
}
extern CREATE_BITRATE_T     qt4CreateBitrate;
extern DELETE_DIA_ELEM_T    qt4DestroyBitrate;
extern CREATE_BAR_T         qt4CreateBar;
extern DELETE_DIA_ELEM_T    qt4DestroyBar;
extern CREATE_FLOAT_T       qt4CreateFloat;
extern DELETE_DIA_ELEM_T    qt4DestroyFloat;
extern CREATE_FRAME_T		qt4CreateFrame;
extern DELETE_DIA_ELEM_T    qt4DestroyFrame;
extern CREATE_HEX_T         qt4CreateHex;
extern DELETE_DIA_ELEM_T    qt4DestroyHex;
extern CREATE_INTEGER_T     qt4CreateInteger;
extern CREATE_UINTEGER_T    qt4CreateUInteger;
extern DELETE_DIA_ELEM_T    qt4DestroyInteger;
extern DELETE_DIA_ELEM_T    qt4DestroyUInteger;
extern CREATE_MATRIX_T      qt4CreateMatrix;
extern DELETE_DIA_ELEM_T    qt4DestroyMatrix;
extern CREATE_NOTCH_T       qt4CreateNotch;
extern DELETE_DIA_ELEM_T    qt4DestroyNotch;
extern CREATE_READONLYTEXT_T qt4CreateRoText;
extern CREATE_TEXT_T 	   qt4CreateText;
extern DELETE_DIA_ELEM_T   qt4DestroyRoText;
extern DELETE_DIA_ELEM_T   qt4DestroyText;
extern CREATE_BUTTON_T     qt4CreateButton;
extern DELETE_DIA_ELEM_T   qt4DestroyButton;
extern CREATE_FILE_T       qt4CreateFile;
extern DELETE_DIA_ELEM_T   qt4DestroyFile;
extern CREATE_DIR_T        qt4CreateDir;
extern DELETE_DIA_ELEM_T   qt4DestroyDir;
extern CREATE_MENUDYNAMIC_T     qt4CreateMenuDynamic;
extern CREATE_MENU_T       qt4CreateMenu;
extern DELETE_DIA_ELEM_T   qt4DestroyMenu;
extern DELETE_DIA_ELEM_T   qt4DestroyMenuDynamic;
extern CREATE_USLIDER_T     qt4CreateUSlider;
extern DELETE_DIA_ELEM_T    qt4DestroyUSlider;
extern 	CREATE_SLIDER_T     qt4CreateSlider;
extern 	DELETE_DIA_ELEM_T   qt4DestroySlider;
extern CREATE_THREADCOUNT_T qt4CreateThreadCount;
extern DELETE_DIA_ELEM_T    qt4DestroyThreadCount;
extern CREATE_TOGGLE_UINT   qt4CreateToggleUint;
extern DELETE_DIA_ELEM_T    qt4DestroyToggleUint;
extern CREATE_TOGGLE_INT    qt4CreateToggleInt;
extern DELETE_DIA_ELEM_T    qt4DestroyToggleInt;
extern CREATE_TOGGLE_T      qt4CreateToggle;
extern DELETE_DIA_ELEM_T    qt4DestroyToggle;

//************
static FactoryDescriptor Qt4FactoryDescriptor=
{
	&qt4FactoryGetVersion,
	&qt4DiaFactoryRun,
	&qt4DiaFactoryRunTabs,
	// Buttons
	&qt4CreateButton,
	&qt4DestroyButton,
	// Bar
	&qt4CreateBar,
	&qt4DestroyBar,
	// Float
	&qt4CreateFloat,
	&qt4DestroyFloat,
	// Integer
	&qt4CreateInteger,
	&qt4DestroyInteger,
	// UInteger
	&qt4CreateUInteger,
	&qt4DestroyUInteger,
	// Notch
	&qt4CreateNotch,
	&qt4DestroyNotch,
	// RoText
	&qt4CreateRoText,
	&qt4DestroyRoText,
	// Text
	&qt4CreateText,
	&qt4DestroyText,
	// Hex
	&qt4CreateHex,
	&qt4DestroyHex,
	// Matrix
	&qt4CreateMatrix,
	&qt4DestroyMatrix,
	// Menu
	&qt4CreateMenu,
	&qt4DestroyMenu,
	&qt4CreateMenuDynamic,
	&qt4DestroyMenuDynamic,
	// ThreadCount
	&qt4CreateThreadCount,
	&qt4DestroyThreadCount,
	// Bitrate
	&qt4CreateBitrate,
	&qt4DestroyBitrate,
	// File
	&qt4CreateFile,
	&qt4DestroyFile,
	// Dir
	&qt4CreateDir,
	&qt4DestroyDir,
	// Frame
	&qt4CreateFrame,
	&qt4DestroyFrame,
    // Toggle uint/int
	&qt4CreateToggleUint,
	&qt4DestroyToggleUint,
	&qt4CreateToggleInt,
	&qt4DestroyToggleInt,
	// Regular toggle
	&qt4CreateToggle,
	&qt4DestroyToggle,
	// Slider
	&qt4CreateUSlider,
	&qt4DestroyUSlider,
	&qt4CreateSlider,
	&qt4DestroySlider
};

/**
 * 	\fn InitFactory
 *  \brief Install our factory hooks
 */
void InitFactory(void)
{
	DIA_factoryInit(&Qt4FactoryDescriptor);
	
	
}

//EOF
