#include "pickcolor.h"


pickcolor::pickcolor(ApplicationManager *pApp):Action(pApp)
{
	n=pManager->GetFigCount();
	f=new CFigure*[n];
	pManager->copyarray(f);
}
void pickcolor::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked (p.x,p.y);
}
bool pickcolor::actiontype()
{
	Input* pIn = pManager->GetInput();
	switch(pIn->GetUserAction(p.x,p.y))
	{
	case pick_both:
		pManager->UpdateInterface();
		pManager->ExecuteAction(pick_both);
		return false;
	case pick_color:
		pManager->UpdateInterface();
		pManager->ExecuteAction(pick_color);
		return false;
	case pick_shape:
		pManager->UpdateInterface();
		pManager->ExecuteAction(pick_shape);
		return false;
	
	case  TO_DRAW:
		pManager->UpdateInterface();
		pManager->ExecuteAction(TO_DRAW);
		return false;
	default:return true;
	}
}
void pickcolor::random(int &w,int &r,int &g,int &b,int&l)
{
	Output* pOut = pManager->GetOutput();
	int ran=std::rand()%5;
	switch(ran)
	{
	case 0:
		if(w==0)
		{
			random(w,r,g,b,l);
		}
		else 
		{
			color=white;
			pOut->PrintMessage("choose white figures :)");
			picking(w);
		}
		break;
	case 1:
		if(b==0)
		{
			random(w,r,g,b,l);
		}
		else 
		{
			color=blue;
			pOut->PrintMessage("choose blue figures :)");
			picking(b);
		}
		break;
	case 2:
		if(r==0)
		{
			random(w,r,g,b,l);
		}
		else 
		{
			color=red;
			pOut->PrintMessage("choose red figures :)");
			picking(r);
		}
		break;
	case 3:
		if(g==0)
		{
			random(w,r,g,b,l);
		}
		else 
		{
			color=green;
			pOut->PrintMessage("choose green figures :)");
			picking(g);
		}
		break;
	case 4:
		if(l==0)
		{
			random(w,r,g,b,l);
		}
		else 
		{
			color=black;
			pOut->PrintMessage("choose black figures :)");
			picking(l);
		}
		break;
	}
}

void pickcolor::Execute()
{
	Input* pIn = pManager->GetInput();
	int l=0,g=0,r=0,b=0,w=0;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you chose :pick by colors ->click to start the game ;) :)");
	pIn->GetUserAction();
	numofcolor(w,r,g,b,l);
	if(n==0)
	{
		pOut->PrintMessage("please draw some figuers and try again :)");
		return;
	}
	else
	{
		if(((w==0)&&(r==0)&&(g==0)&&(b==0)&&(l==0)))
		{
			pOut->PrintMessage("please draw some with colors figuers and try again :)");
			return;
		}
		else
		{
			random(w,r,g,b,l);
		}
	}
}
void pickcolor::numofcolor(int & w,int & r,int & g,int & b,int& l)
{
	for(int i=0;i<n;i++)
	{
		if(dynamic_cast<CLine*>(f[i])!=NULL)
		{	
			if(((int)(f[i]->getdrawcol().ucBlue) == 255) &&  ((int)(f[i]->getdrawcol().ucGreen) == 0)  &&  ((int)(f[i]->getdrawcol().ucRed) == 0))
			{
				b++;
			}
			else if(((int)(f[i]->getdrawcol().ucGreen) == 255) &&  ((int)(f[i]->getdrawcol().ucBlue) == 0)  &&  ((int)(f[i]->getdrawcol().ucRed) == 0))
			{
				g++;
			} 
			else if(((int)(f[i]->getdrawcol().ucRed) == 255) &&  ((int)(f[i]->getdrawcol().ucGreen) == 0)  &&  ((int)(f[i]->getdrawcol().ucBlue) == 0))
			{
				r++;
			}
			else if(((int)(f[i]->getdrawcol().ucBlue) == 0)  &&  ((int)(f[i]->getdrawcol().ucGreen) == 0)  &&  ((int)(f[i]->getdrawcol().ucRed) == 0))
			{
				l++;
			}
			else if(((int)(f[i]->getdrawcol().ucBlue) == 255)  &&  ((int)(f[i]->getdrawcol().ucGreen) == 255)  &&  ((int)(f[i]->getdrawcol().ucRed) == 255))
			{
				w++;
			}
		}
		else
		{
			if(((int)(f[i]->getfillcol().ucBlue) == 255) &&  ((int)(f[i]->getfillcol().ucGreen) == 0)  &&  ((int)(f[i]->getfillcol().ucRed) == 0))
			{
				b++;
			}
			else if(((int)(f[i]->getfillcol().ucGreen) == 255) &&  ((int)(f[i]->getfillcol().ucBlue) == 0)  &&  ((int)(f[i]->getfillcol().ucRed) == 0))
			{
				g++;
			}
			else if(((int)(f[i]->getfillcol().ucRed) == 255) &&  ((int)(f[i]->getfillcol().ucGreen) == 0)  &&  ((int)(f[i]->getfillcol().ucBlue) == 0))
			{
				r++;
			}
			else if(((int)(f[i]->getfillcol().ucBlue) == 0)  &&  ((int)(f[i]->getfillcol().ucGreen) == 0)  &&  ((int)(f[i]->getfillcol().ucRed) == 0))
			{
				l++;
			}
			else if(((int)(f[i]->getfillcol().ucBlue) == 255)  &&  ((int)(f[i]->getfillcol().ucGreen) == 255)  &&  ((int)(f[i]->getfillcol().ucRed) == 255))
			{
				w++;
			}

		}
	}
}
void pickcolor::picking(int n)
{
	int wronganswer=0,rightanswer=0;
	bool exit=true;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (rightanswer!=n && exit)
	{
		ReadActionParameters();
		if(p.y >= 0 && p.y < UI.ToolBarHeight)
		{
			exit=actiontype();
		}
		else
		{

			if(getfigtype(pManager->GetFigures(p.x,p.y)))
			{
				rightanswer++;

			}
			else 
			{  
				wronganswer++;
			}
			deletefig(pManager->GetFigures(p.x,p.y));
			print(rightanswer,wronganswer);
			pOut->ClearDrawArea();
			UpdateInterface();
		}
	}
	if(!exit)
	{
		return;
	}
	else
	{
		pOut->PrintMessage("congratulations you finished the game ->click to get your score :)");
		pIn->GetUserAction();
		print(rightanswer,wronganswer);
	}
}
void pickcolor::deletefig(CFigure* p)
{
	for(int i=0;i<n;i++)
	{
		if(p == f[i])
		{
			f[i] = NULL;
			for (int j = i +1; j < n ; j++)
			{
				f[j-1] = f[j]; 
			}
			n--;
			return;
		}
	} 
}
bool pickcolor::getfigtype(CFigure* p)
{
	if(dynamic_cast<CLine*>(p) !=NULL)
	{
		switch(color)
		{
		case black:
			if(((int)(p->getdrawcol().ucBlue) == 0)  &&  ((int)(p->getdrawcol().ucGreen) == 0)  &&  ((int)(p->getdrawcol().ucRed) == 0))
				return true;
			else 
				return false;
		case blue:
			if((int)(p->getdrawcol().ucBlue) == 255 && ((int)(p->getdrawcol().ucGreen) == 0)  &&  ((int)(p->getdrawcol().ucRed) == 0))
				return true;
			else 
				return false;
		case red:
			if((int)(p->getdrawcol().ucRed) == 255 && ((int)(p->getdrawcol().ucBlue) == 0)  &&  ((int)(p->getdrawcol().ucGreen) == 0))
				return true;
			else 
				return false;
		case green :
			if((int)(p->getdrawcol().ucGreen) == 255 && ((int)(p->getdrawcol().ucBlue) == 0)  &&  ((int)(p->getdrawcol().ucRed) == 0))
				return true;
			else 
				return false;
		case white:
			if(((int)(p->getdrawcol().ucBlue) == 255)  &&  ((int)(p->getdrawcol().ucGreen) == 255)  &&  ((int)(p->getdrawcol().ucRed) == 255))
				return true;
			else 
				return false;
		}
	}
	else
	{
		switch(color)
		{
		case black:
			if(((int)(p->getfillcol().ucBlue) == 0)  &&  ((int)(p->getfillcol().ucGreen) == 0)  &&  ((int)(p->getfillcol().ucRed) == 0))
				return true;
			else 
				return false;
		case blue:
			if((int)(p->getfillcol().ucBlue) == 255 && ((int)(p->getfillcol().ucGreen) == 0)  &&  ((int)(p->getfillcol().ucRed) == 0))
				return true;
			else 
				return false;
		case red:
			if((int)(p->getfillcol().ucRed) == 255 && ((int)(p->getfillcol().ucBlue) == 0)  &&  ((int)(p->getfillcol().ucGreen) == 0))
				return true;
			else 
				return false;
		case green :
			if((int)(p->getfillcol().ucGreen) == 255 && ((int)(p->getfillcol().ucBlue) == 0)  &&  ((int)(p->getfillcol().ucRed) == 0))
				return true;
			else 
				return false;
		case white:
			if(((int)(p->getfillcol().ucBlue) == 255)  &&  ((int)(p->getfillcol().ucGreen) == 255)  &&  ((int)(p->getfillcol().ucRed) == 255))
				return true;
			else 
				return false;
		}
	}
}
void pickcolor::UpdateInterface() const
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	for(int i=0; i<n; i++)
	{
		f[i]->Draw(pOut);		
	}
}
void pickcolor::print(int r,int w)
{
	Output* pOut = pManager->GetOutput();
	string l=to_string(r);
	string s=to_string(w);
	pOut->PrintMessage("right:"+l+"                 wrong:"+s);
}
pickcolor::~pickcolor(void)
{
	delete [] f;
}
