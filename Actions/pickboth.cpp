#include "pickboth.h"
#include <cstringt.h>
pickboth::pickboth(ApplicationManager *pApp):Action(pApp)
{
	n=pManager->GetFigCount();
	f=new CFigure*[n];
	pManager->copyarray(f);
}
void pickboth:: ReadActionParameters()
{

	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked (p.x,p.y);

}
bool pickboth::actiontype()
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
void pickboth :: Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you chose :pick by shape & color ->click to start the game ;) :)");
	pIn->GetUserAction();
	int c=0,t=0,r=0,l=0;
	int wh=0,re=0,bl=0,bk=0,gr=0;
	if((n!=0)&&!(checkcolor()))
	{
		while((wh==0)&&(re==0)&&(bl==0)&&(bk==0)&&(gr==0))
		{
			numshape(c,t,r,l);
			randoms(c,t,r,l);
			numcolor(wh,re,bl,bk,gr);
		}
		randomc(wh,re,bl,bk,gr);
	}
	else
	{
		pOut->PrintMessage("please draw some figuers with colors and try again :)");
		return;
	}
}
bool pickboth ::checkcolor()
{
	int l,b,r,g,w;
	l=w=g=r=b=0;
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
	if((w==0)&&(r==0)&&(l==0)&&(b==0)&&(g==0))
	{
		return true;
	}
	else
		return false;
}
void pickboth :: numshape (int&c,int&t,int&r,int&l)
{
	for (int i=0;i<n;i++)
	{
		if (dynamic_cast<CCircle*>(f[i]) != NULL)
		{
			c++;
		}
		else if (dynamic_cast<CTriangle*>(f[i]) != NULL)
		{
			t++;
		}
		else if (dynamic_cast<CRectangle*>(f[i]) != NULL)
		{
			r++;
		}
		else 
		{
			l++;
		}
	}
}
void pickboth :: numcolor (int&w,int&r,int&b,int&l,int&g)
{
	switch(shape)
	{
	case circle:
		for(int i=0;i<n;i++)
		{
			if(dynamic_cast<CCircle*>(f[i]) != NULL)
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
		break;
	case triangle:
		for(int i=0;i<n;i++)
		{
			if(dynamic_cast<CTriangle*>(f[i]) != NULL)
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
		break;
	case rectangle:
		for(int i=0;i<n;i++)
		{
			if(dynamic_cast<CRectangle*>(f[i]) != NULL)
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
		break;
	case line:
		for(int i=0;i<n;i++)
		{
			if(dynamic_cast<CLine*>(f[i]) != NULL)
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
		}
		break;
	}
}//wh,re,bl,bk,gr
void pickboth :: randoms (int &c,int &t,int &r,int &l)
{
	Output* pOut = pManager->GetOutput();
	int ran=std::rand()%4;
	switch(ran)
	{
	case 0:
		if(c ==0)
		{
			randoms(c,t,r,l);
		}
		else 
		{
			shape=circle;
		}
		break;
	case 1:
		if(t ==0)
		{
			randoms(c,t,r,l);
		}
		else 
		{
			shape=triangle;
		}
		break;
	case 2:
		if(r ==0)
		{
			randoms(c,t,r,l);
		}
		else 
		{
			shape=rectangle;
		}
		break;
	case 3:
		if(l ==0)
		{
			randoms(c,t,r,l);
		}
		else 
		{
			shape=line;
		}
		break;
	}
}//wh,re,bl,bk,gr
void pickboth::randomc (int & wh,int & re,int & bl,int & bk,int& gr)
{
	Output* pOut = pManager->GetOutput();
	int ran=std::rand()%5;
	switch(ran)
	{
	case 0:
		if(wh==0)
		{
			randomc(wh,re,bl,bk,gr);
		}
		else 
		{
			color=white;
			switch (shape)
			{
			case circle:
				pOut->PrintMessage("choose white circle ");
				break;
			case triangle:
				pOut->PrintMessage("choose white triangle ");
				break;
			case rectangle:
				pOut->PrintMessage("choose white rectangle ");
				break;
			case line:
				pOut->PrintMessage("choose white line");
				break;
			}
			picking(wh);
		}
		break;
	case 1:
		if(bl==0)
		{
			randomc(wh,re,bl,bk,gr);
		}
		else 
		{
			color=blue;
			switch (shape)
			{
			case circle:
				pOut->PrintMessage("choose blue circle ");
				break;
			case triangle:
				pOut->PrintMessage("choose blue triangle ");
				break;
			case rectangle:
				pOut->PrintMessage("choose blue rectangle ");
				break;
			case line:
				pOut->PrintMessage("choose blue line");
				break;
			}
			picking(bl);
		}
		break;
	case 2:
		if(re==0)
		{
			randomc(wh,re,bl,bk,gr);
		}
		else 
		{
			color=red;
			switch (shape)
			{
			case circle:
				pOut->PrintMessage("choose red circle ");
				break;
			case triangle:
				pOut->PrintMessage("choose red triangle ");
				break;
			case rectangle:
				pOut->PrintMessage("choose red rectangle ");
				break;
			case line:
				pOut->PrintMessage("choose red line");
				break;
			}
			picking(re);
		}
		break;
	case 3:
		if(gr==0)
		{
			randomc(wh,re,bl,bk,gr);
		}
		else 
		{
			color=green;
			switch (shape)
			{
			case circle:
				pOut->PrintMessage("choose green circle ");
				break;
			case triangle:
				pOut->PrintMessage("choose green triangle ");
				break;
			case rectangle:
				pOut->PrintMessage("choose green rectangle ");
				break;
			case line:
				pOut->PrintMessage("choose green line");
				break;
			}
			picking(gr);
		}
		break;
	case 4:
		if(bk==0)
		{
			randomc(wh,re,bl,bk,gr);
		}
		else 
		{
			color=black;
			switch (shape)
			{
			case circle:
				pOut->PrintMessage("choose black circle ");
				break;
			case triangle:
				pOut->PrintMessage("choose black triangle ");
				break;
			case rectangle:
				pOut->PrintMessage("choose black rectangle ");
				break;
			case line:
				pOut->PrintMessage("choose black line");
				break;
			}
			picking(bk);
		}
		break;

	}
}
void pickboth :: picking(int num)
{
	int wronganswer=0,rightanswer=0;
	bool exit=true;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (rightanswer!=num &&exit)
	{
		ReadActionParameters();
		if(p.y >= 0 && p.y < UI.ToolBarHeight)
		{
			exit=actiontype();
		}
		else
		{
			if((figtypes(pManager->GetFigures(p.x,p.y))) && (figtypec(pManager->GetFigures(p.x,p.y))))
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
bool pickboth :: figtypes(CFigure*p)
{
	if(shape==circle)
	{
		if (dynamic_cast<CCircle*>(p) !=NULL)
			return true;
		else
			return false;
	}
	else if(shape==triangle)
	{
		if(dynamic_cast<CTriangle*>(p) !=NULL)
			return true;
		else
			return false;
	}
	else if(shape==rectangle)
	{
		if(dynamic_cast<CRectangle*>(p) !=NULL)
			return true;
		else
			return false;
	}
	else
	{
		if(dynamic_cast<CLine*>(p) !=NULL)
			return true;
		else
			return false;
	}
}
bool pickboth :: figtypec(CFigure*p)
{
	if(shape == line)
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
void pickboth::deletefig(CFigure*p)
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
void pickboth::UpdateInterface() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	for(int i=0; i<n; i++)
	{
		f[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
void pickboth::print(int r,int w)
{
	Output* pOut = pManager->GetOutput();
	string l=to_string(r);
	string s=to_string(w);
	pOut->PrintMessage("right:"+l+"                 wrong:"+s);
}
pickboth::~pickboth(void)
{
	delete [] f;
}
