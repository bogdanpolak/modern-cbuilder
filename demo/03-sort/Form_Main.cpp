//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#include <algorithm>

#pragma hdrstop

#include "Form_Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
static const unsigned int MAX_VALUE = 1000;
static std::vector<int> data;
// ---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
}
//---------------------------------------------------------------------------
void boardFillWithRandomData (int count) {
	data.clear();
	for (int i = 0; i < count; i++)
		data.push_back ( Random(MAX_VALUE) );
}
//---------------------------------------------------------------------------
static float HueToRGB(float v1, float v2, float vH) {
	if (vH < 0) vH += 1;
	if (vH > 1) vH -= 1;
	if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1) return v2;
	if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return v1;
}
//---------------------------------------------------------------------------
void TForm1::DrawBoardItem (int index) {
	TCanvas* canvas = PaintBox1->Canvas;
	int boardHeight = PaintBox1->Height;
	int x = index*3;
	int value = data[index];
	int len = boardHeight * value / MAX_VALUE;
	// ----------------------------------------------
	// CalculateVclColor for (hue = value/MAX_VALUE, sat=100%, light=35% );
	float hue = (float)value/MAX_VALUE;
	float light = 0.35f;
	float v2 = light * 2;
	float v1 = 2 * light - v2;
	unsigned char r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
	unsigned char g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
	unsigned char b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
	// ----------------------------------------------
	canvas->Pen->Color = TColor(RGB(r,g,b));
	canvas->Rectangle (x,0,x+2,len);
	canvas->Pen->Color = clWhite;
	canvas->Rectangle (x,len,x+2,boardHeight);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
	for (unsigned int i=0; i<data.size(); i++) {
		DrawBoardItem(i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	int count = PaintBox1->Width / 3;
	boardFillWithRandomData (count);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void TForm1::VisualSwapBoardItems (int i, int j) {
	std::swap(data[i],data[j]);
	DrawBoardItem(i);
	DrawBoardItem(j);
	for (int i=0; i < 100000; i++) { }  // sleep < 1ms
}
//---------------------------------------------------------------------------
void TForm1::qsort(int L, int R) {
	int i, j, mid, piv;
	i = L;
	j = R;
	mid = L + (R - L) / 2;
	piv = data[mid];
	while (i<R || j>L) {
		while (data[i] < piv)
			i++;
		while (data[j] > piv)
			j--;
		if (i <= j) {
			// swap(i, j);
            VisualSwapBoardItems(i, j);
			i++;
			j--;
		} else {
			if (i < R) qsort(i, R);
			if (j > L) qsort(L, j);
			return;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actRunQuickSortExecute(TObject *Sender)
{
	unsigned long enlapsedMs = 0;
	unsigned long start = GetTickCount();
	// ----------------------------------------------
	// Algorithm: Quick Sort
	qsort(0, data.size() - 1);
	// ----------------------------------------------
	enlapsedMs = GetTickCount() - start;
	Caption = L"[Results] QuickSort: "+
		FormatFloat(L"###,###",enlapsedMs) + " ms";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actRunBubbleSortExecute(TObject *Sender)
{
	unsigned long enlapsedMs = 0;
	unsigned long start = GetTickCount();
	// ----------------------------------------------
	// Algorithm: Bubble Sort
	for(unsigned int i = 0; i < data.size(); i++ )
		for(unsigned int j = 0; j < data.size() - 1; j++ ) {
			if( data[j] > data[j+1] ) {
				// swap( j, j+1 );
				VisualSwapBoardItems(j, j+1);
			}
		}
	// ----------------------------------------------
	enlapsedMs = GetTickCount() - start;
	Caption = L"[Results] BubbleSort: "+
		FormatFloat(L"###,###",enlapsedMs) + " ms.";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actShuflleDataExecute(TObject *Sender)
{
	int count = PaintBox1->Width / 3;
	boardFillWithRandomData (count);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------

