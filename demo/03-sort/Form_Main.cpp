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
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
namespace hsl {
	static float HueToRGB(float v1, float v2, float vH) {
		if (vH < 0) vH += 1;
		if (vH > 1) vH -= 1;
		if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
		if ((2 * vH) < 1) return v2;
		if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
		return v1;
	}
	static TColor CalculateVclColor(int H, float S, float L) {
		unsigned char r = 0;
		unsigned char g = 0;
		unsigned char b = 0;
		if (S == 0) {
			r = g = b = (unsigned char)(L * 255);
		} else {
			float v1, v2;
			float hue = (float)H / 360;
			v2 = (L < 0.5) ? (L * (1 + S)) : ((L + S) - (L * S));
			v1 = 2 * L - v2;

			r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
			g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
			b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
		}
		return TColor(RGB(r,g,b));
	}
}
//---------------------------------------------------------------------------
struct Board;
struct CustomBoardView {
	CustomBoardView () {};
	virtual void visualizeSwap (const Board& borad, int i, int j) = 0;
};

struct Board {
	static const unsigned int MAX_VALUE = 1000;
	std::vector<int> data;
	CustomBoardView* sortView;
	Board () {};
	Board (int count) {
		fillVectorItems(count);
	}
	void fillRandomData (int count) {
		data.empty();
		fillVectorItems(count);
	}
	void quicksort(CustomBoardView& view) {
		sortView = &view;
		qsort(0, data.size() - 1);
	}
	void quicksort(CustomBoardView& view) {
		sortView = &view;
		qsort(0, data.size() - 1);
	}
private:
	void fillVectorItems (int count) {
		for (int i = 0; i < count; i++)
			data.push_back ( Random(MAX_VALUE) );
	}
	void swap (int i, int j) {
		std::swap(data[i],data[j]);
		sortView->visualizeSwap(*this,i,j);
	}
	void qsort(int L, int R) {
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
				swap(i, j);
				i++;
				j--;
			} else {
				if (i < R) qsort(i, R);
				if (j > L) qsort(L, j);
				return;
			}
		}
	}
};
//---------------------------------------------------------------------------
void drawBoardItem (const Board& board, int index, TCanvas* canvas, int boardHeight) {
	int x = index*3;
	int val = board.data[index];
	int len = boardHeight * val / Board::MAX_VALUE;
	int hue = (int)(360.0f*val/Board::MAX_VALUE);
	canvas->Pen->Color = hsl::CalculateVclColor(hue , 1.00f, 0.35f);
	canvas->Rectangle (x,0,x+2,len);
	canvas->Pen->Color = clWhite;
	canvas->Rectangle (x,len,x+2,boardHeight);
}

void drawBoard(const Board& board, TPaintBox* paintbox)
{
	for (unsigned int i=0; i<board.data.size(); i++) {
		drawBoardItem(board,i,paintbox->Canvas,paintbox->Height);
	}
}
//---------------------------------------------------------------------------
static Board board;
//---------------------------------------------------------------------------
struct VclBoardView : CustomBoardView {
	TPaintBox* fPaintBox;
	VclBoardView (TPaintBox* aPaintBox1) : fPaintBox(aPaintBox1) {};
	virtual void visualizeSwap (const Board& borad, int i, int j) {
		drawBoardItem(board,i,fPaintBox->Canvas,fPaintBox->Height);
		drawBoardItem(board,j,fPaintBox->Canvas,fPaintBox->Height);
		for (int i=0; i < 2000000; i++) { }  // sleep < 1ms
		// Sleep(1);
	};
};

//---------------------------------------------------------------------------

void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
	board = Board(PaintBox1->Width / 3);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
	drawBoard (board,PaintBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	board.quicksort( VclBoardView(PaintBox1) );
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	board = Board(PaintBox1->Width / 3);
	PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
