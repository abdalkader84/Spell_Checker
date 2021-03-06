//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "hash_class.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
hash_table tbl(25000);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Lines->LoadFromFile("..\\..\\EN_Word_25.txt");
	for (int i=0; i<Memo1->Lines->Count; i++) {
		tbl.insert(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i]);
	}
}

void __fastcall TForm1::Highlight()
{
	CHARFORMAT2 CF;
	CF.cbSize=sizeof(CF);
	CF.dwMask=CFM_BACKCOLOR;
	CF.dwEffects=CFE_PROTECTED;
	CF.crBackColor=clYellow;
	RichEdit1->Perform(EM_SETCHARFORMAT , (WPARAM) SCF_SELECTION , (LPARAM) &CF);
}
void __fastcall TForm1::reset_Highlight()
{
	RichEdit1->SelStart=0;
	RichEdit1->SelLength=RichEdit1->Text.Length();

	CHARFORMAT2 CF;
	CF.cbSize=sizeof(CF);
	CF.dwMask=CFM_BACKCOLOR;
	CF.dwEffects=CFE_PROTECTED;
	CF.crBackColor=clWhite;
	RichEdit1->Perform(EM_SETCHARFORMAT , (WPARAM) SCF_SELECTION , (LPARAM) &CF);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	reset_Highlight();
	String wrd="";
	int i=1;
	for (i =1; i<=RichEdit1->Text.Length(); i++) {
		char ch=RichEdit1->Text[i];
		if (ch==' ') {
			if (tbl.find(wrd)=="") {
				RichEdit1->SelStart=i-1-wrd.Length();
				RichEdit1->SelLength=wrd.Length();
				Highlight();
			}
            wrd="";
		}
		else
		{
			wrd+=ch;
        }
	}
	if (wrd!="") {
        if (tbl.find(wrd)=="") {
			RichEdit1->SelStart=i-1-wrd.Length();
			RichEdit1->SelLength=wrd.Length();
			Highlight();
		}
	}
}
//---------------------------------------------------------------------------
