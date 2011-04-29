//---------------------------------------------------------------------------


#pragma hdrstop
#include "Unit1.h" // ������ ������� ��������
#include "Unit3.h" // ������, �� ������ �����

//---------------------------------------------------------------------------

#pragma package(smart_init)

 void TPizza::getdata(AnsiString& a1,AnsiString& a2,AnsiString& a3) //������ ���
{

strncpy(name,a1.c_str(),50);
weight=StrToInt(a2);
amount=1;
price=StrToInt(a3);

};
//---------------------------------------------------------------------------


void TPizza::ShowError()   //�������� ������� ��� ����������
{
   if (Application->MessageBox("�������� ���� ����� �� ����",
            "�������",MB_OK)==IDOK);



}

void TPizza::diskRead(int pn)   //������� �������� ���� ��� �������
{
ifstream infile;
infile.open("Pizza.dat",ios::binary);
infile.seekg(pn*sizeof(TPizza));
infile.read((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
void TPizza::diskWrite()  //�������� ����� � ����� ��������� � �����
{
ofstream outfile;
outfile.open("Pizza.dat",ios::app|ios::binary);
outfile.write((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
void TPizza::diskDel()      //������� ��� �� ����� ���� �� ����
{
ofstream outfile;
outfile.open("Pizza.dat",ios::trunc|ios::binary);  ///���� ���� ���� ������ ����
outfile.write((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
int TPizza::diskCount()        //������� ������� �������� � ����
{
TPizza per;
ifstream infile;
infile.open("Pizza.dat",ios::binary);
infile.seekg(0,ios::end);
return(int)(infile.tellg()/64);
};
//---------------------------------------------------------------------------



void TViewEvent::ShowData(TStringGrid& tr,int n)   //�������� ������� ������
{number=n;
tr.Cells[0][n]=IntToStr(number);
tr.Cells[1][n]=name;
tr.Cells[2][n]=IntToStr(weight);
tr.Cells[3][n]=IntToStr(amount);
tr.Cells[4][n]=FloatToStr(price);

};
//---------------------------------------------------------------------------
void TViewEvent::ShowRow(TStringGrid& row)     //�������� 1 ����� �������
{
row.Cells[0][0]="�";
row.Cells[1][0]="����� ���������";
row.Cells[2][0]="����";
row.Cells[3][0]="�-���";
row.Cells[4][0]="ֳ��";

} ;

//---------------------------------------------------------------------------
void TViewEvent::ShowError()         //�������� �������, ���� �� ������ ������� ��'����
{
if (Application->MessageBox("������ ������, ������ ����� ���������",
            "�������",MB_OK)==IDOK);

}
//-------------------------------------------------------------------------
void TViewEvent::Look(TStringGrid& tr)  //������ �� �������� ������ ��� ��������� ����� �� �����
{

int n=m.diskCount();
tr.RowCount=n+1;
for(int i=0;i<n;i++)
{
m.diskRead(i);
m.ShowData(tr,i+1);
}

}
