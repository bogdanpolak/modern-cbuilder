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


// ---------------------------------------------------------------------------
//  HslConverter.cpp
//  Hue Saturation Light - Colors Converter
// ---------------------------------------------------------------------------
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

// ---------------------------------------------------------------------------
// Board.cpp / BoardView.cpp
// ---------------------------------------------------------------------------
struct Board;

struct BoardView {
	BoardView () {};
	virtual void visualizeSwap (const Board& borad, int i, int j) = 0;
};

// ---------------------------------------------------------------------------
// Board.cpp
// ---------------------------------------------------------------------------
struct Board {
	static const unsigned int MAX_VALUE = 1000;
	std::vector<int> data;
	BoardView* sortView;
	Board () {};
	Board (int count) {
		fillVectorItems(count);
	}
	void fillRandomData (int count) {
		data.empty();
		fillVectorItems(count);
	}
	void quicksort(BoardView& view) {
		sortView = &view;
		qsort(0, data.size() - 1);
	}
	void bubblesort(BoardView& view) {
		sortView = &view;
		for(unsigned int i = 0; i < data.size(); i++ )
			for(unsigned int j = 0; j < data.size() - 1; j++ ) {
				if( data[j] > data[j+1] )
					swap( j, j+1 );
			}
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

// ---------------------------------------------------------------------------
// BoardDraw.cpp
// ---------------------------------------------------------------------------
struct BoardDraw {
	static void drawBoardItem (int value, int index, TCanvas* canvas,
		int boardHeight)
	{
		int x = index*3;
		int len = boardHeight * value / Board::MAX_VALUE;
		int hue = (int)(360.0f*value/Board::MAX_VALUE);
		canvas->Pen->Color = hsl::CalculateVclColor(hue , 1.00f, 0.35f);
		canvas->Rectangle (x,0,x+2,len);
		canvas->Pen->Color = clWhite;
		canvas->Rectangle (x,len,x+2,boardHeight);
	}

	static void drawBoard(const Board& board, TPaintBox* paintbox)
	{
		for (unsigned int i=0; i<board.data.size(); i++) {
			drawBoardItem(board.data[i],i,paintbox->Canvas,paintbox->Height);
		}
	}
};

// ---------------------------------------------------------------------------
// BoardVclView.cpp
// ---------------------------------------------------------------------------
struct BoardVclView : BoardView {
	TPaintBox* paintbx;
	BoardVclView (TPaintBox* aPaintBox1) : paintbx(aPaintBox1) {};
	virtual void visualizeSwap (const Board& board, int i, int j) {
		int vi = board.data[i];
		int vj = board.data[j];
		TThread::Synchronize(NULL, [&]() {
			BoardDraw::drawBoardItem(vi,i,paintbx->Canvas,paintbx->Height);
			BoardDraw::drawBoardItem(vj,j,paintbx->Canvas,paintbx->Height);
		});
		for (int i=0; i < 100000; i++) { }  // sleep < 1ms
		// Sleep(1);
	};
};

//---------------------------------------------------------------------------
// Form_Main.hpp
//---------------------------------------------------------------------------
static Board boardQS;
static Board boardBS;


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
	BoardDraw::drawBoard (boardQS,PaintBox1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox2Paint(TObject *Sender)
{
	BoardDraw::drawBoard (boardBS,PaintBox2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	enlapsedMsQuickSort = 0;
	enlapsedMsBubbleSort = 0;
	TThread *threadQuickSort = TThread::CreateAnonymousThread(
		[&]() {
			BoardVclView view(PaintBox1);
			unsigned long start = GetTickCount();
			boardQS.quicksort( view );
			enlapsedMsQuickSort = GetTickCount() - start;
		}
	);
	TThread *threadBubbleSort = TThread::CreateAnonymousThread(
		[&]() {
			BoardVclView view(PaintBox2);
			unsigned long start = GetTickCount();
			boardBS.bubblesort( view );
			enlapsedMsBubbleSort = GetTickCount() - start;
		}
	);
	threadBubbleSort->OnTerminate = &ThreadTerminated;
	Button1->Enabled = false;
	threadQuickSort->Start();
	threadBubbleSort->Start();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ThreadTerminated(TObject *Sender) {
	Button1->Enabled = true;
	Caption = L"[Results] QuickSort: "+
		FormatFloat(L"###,###",enlapsedMsQuickSort) + " ms.   BubbleSort: "+
		FormatFloat(L"###,###",enlapsedMsBubbleSort) + " ms.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	boardQS = Board(PaintBox1->Width / 3);
	PaintBox1->Invalidate();
	boardBS = Board(PaintBox2->Width / 3);
	PaintBox2->Invalidate();
}
//---------------------------------------------------------------------------

