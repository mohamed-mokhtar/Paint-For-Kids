#include "pickshape.h"
#include<cstring>
pickshape::pickshape(ApplicationManager *pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	n=pManager->GetFigCount();
	f=new CFigure*[n];
	pManager->copyarray(f);
}
void pickshape::ReadActionParameters() 
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked (p.x,p.y);
}
bool pickshape::actiontype()
{
	Input* pIn = pManager->GetInput();
	pManager->UpdateInterface();
	
	
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
		pManager->ExecuteAction(TO_DRAW);
		return false;

	default:return true;
	
	
	
	
	}

}
void pickshape::numofig(int& l,int& t,int& r,int& c)
{
	for(int i=0;i<n;i++)
	{
		if(dynamic_cast<CCircle*>(f[i]) !=NULL)
			c++;
		else if(dynamic_cast<CTriangle*>(f[i]) !=NULL)
			t++;
		else if(dynamic_cast<CRectangle*>(f[i]) !=NULL)
			r++;
		else
			l++;
	}
}
void pickshape::Execute() 
{
	Input* pIn = pManager->GetInput();
	int l=0,c=0,r=0,t=0;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("you chose :pick by shape ->click to start the game ;) :)");
	pIn->GetUserAction();
	if(n==0)
	{
		pOut->PrintMessage("please draw some figuers and try again :)");
		return;
	}
	else
	{
		numofig(l,t,r,c);
		random(l,t, r,c);
	}
}
void pickshape::random(int& l,int& t,int& r,int& c)
{
	Output* pOut = pManager->GetOutput();
	int ran=std::rand()%4;
	switch(ran)
	{
	case 0:
		if(c ==0)
		{
			random(l,t,r,c);
		}
		else 
		{
			shape=circle;
			pOut->PrintMessage("choose the circles :)");
			picking(c);

		}
		break;
	case 1:
		if(t ==0)
		{
			random(l,t,r,c);
		}
		else 
		{
			shape=triangle;
			pOut->PrintMessage("choose the triangles :)");
			picking(t);
		}
		break;
	case 2:
		if(r ==0)
		{
			random(l,t,r,c);
		}
		else 
		{
			shape=rectangle;
			pOut->PrintMessage("choose the rectangles :)");
			picking(r);
		}
		break;
	case 3:
		if(l ==0)
		{
			random(l,t,r,c);
		}
		else 
		{
			shape=line;
			pOut->PrintMessage("choose the lines :)");
			picking(l);
		}
		break;
	}
}
bool pickshape:: getfigtype(CFigure* p)
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
void pickshape::picking(int num)
{
	int wronganswer=0,rightanswer=0;
	bool exit=true;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	while (rightanswer!=num && exit)
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
void pickshape::print(int r,int w)
{
	Output* pOut = pManager->GetOutput();
	string l=to_string(r);
	string s=to_string(w);
	pOut->PrintMessage("right:"+l+"                 wrong:"+s);
}
void pickshape::UpdateInterface() const
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	for(int i=0; i<n; i++)
	{
		f[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
void pickshape::deletefig(CFigure*p)
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
pickshape::~pickshape(void)
{
	delete [] f;
}
