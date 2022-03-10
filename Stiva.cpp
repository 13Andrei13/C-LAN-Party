#include "Stiva.h"
#include "Echipa.h"

#include<iomanip>

Stiva::~Stiva()
{
    if(this->next != nullptr)
        delete this->next;
    
    memset(this, 0, sizeof(Stiva));
}

void Stiva::fafis(ofstream& out)
{
    if(this->getNext() == nullptr)
    {
        char str[16];

        sprintf(str, "%.2f", e->getPoe(e->getPl(), e->getNr()));
        
        out << this->e->getNu()<< setw(38 - this->e->getNu().length()) << " -  " << str << endl;

        return;
    }
    this->getNext()->fafis(out);
    char str[16];

    sprintf(str, "%.2f", e->getPoe(e->getPl(), e->getNr()));
    
    out << this->e->getNu()<< setw(37 - this->e->getNu().length()) << "-  " << str << endl;
}
void Stiva::fafisf(ofstream& out)
{
    Echipa* aux = this->e;

    
    while(aux != NULL)
    {
        char str[16];
        sprintf(str, "%.2f", aux->getPoe(aux->getPl(), aux->getNr()));
        out << aux->getNu()<< setw(37 - aux->getNu().length()) << "-  " << str << endl;

        aux = aux->next;
    }
    /*char str[16];
    sprintf(str, "%.2f", e->getPoe(e->getPl(), e->getNr()));
    
    out << this->e->getNu()<< setw(38 - this->e->getNu().length()) << "-  " << str << endl;

    if(this->getNext() != nullptr)
        this->getNext()->fafisf(out);
    */
}

void Stiva::add_position(int pos,Echipa* n)
{
  Echipa *pre = new Echipa();
  Echipa *cur = new Echipa();
  Echipa *temp = new Echipa();
  
  if(pos==0)
  {
    temp->setNr(n->getNr());
    temp->setNu(n->getNu());
    temp->setPl(n->getPl());
    temp->next = this->e;
    this->e = temp;
  }
  else
  {
    cur=this->get();
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    temp->setNr(n->getNr());
    temp->setNu(n->getNu());
    temp->setPl(n->getPl());
    temp->next = cur;
    pre->next = temp;
  }
}

Stiva::Stiva(Meciuri* meciuri, int type)
{
    if(meciuri == nullptr)
        return;
    

    switch (type)
    {
    case 0:
        {
            Meciuri* aux = meciuri;
            while(aux != nullptr)
            {
                Echipa* ec1 = aux->getEc1();
                Echipa* ec2 = aux->getEc2();

                if(ec1->getPoe(ec1->getPl(), ec1->getNr()) > ec2->getPoe(ec2->getPl(), ec2->getNr()))
                {
                    ec1->setPoe(ec1->getPl(), ec1->getNr());
                    this->add_position(0, ec1);

                    
                    
                } else
                {
                    ec2->setPoe(ec2->getPl(), ec2->getNr());
                    this->add_position(0, ec2);
                }

                aux = aux->getNex();
            }
            /*if(ec1->getPoe(ec1->getPl(), ec1->getNr()) >= ec2->getPoe(ec2->getPl(), ec2->getNr()))
            {   
                ec1->setPoe(ec1->getPl(), ec1->getNr());
                this->e = ec1;
                if(meciuri->getNex() != nullptr)
                    this->next = new Stiva(meciuri->getNex(), type);
            } else {
                 
                ec2->setPoe(ec2->getPl(), ec2->getNr());
                this->e = ec2;

                if(meciuri->getNex() != nullptr)
                    this->next = new Stiva(meciuri->getNex(), type);

                

            }  */ 
        }
        break;
    
    /*case 1:
        {
            if(ec1->getPoe(ec1->getPl(), ec1->getNr()) >= ec2->getPoe(ec2->getPl(), ec2->getNr()))
            {    
                if(meciuri->getNex() != nullptr)
                    this->next = new Stiva(meciuri->getNex(), type);
                ec1->setPoe(ec1->getPl(), ec1->getNr());
                this->e = ec2;
            } else {
                
                if(meciuri->getNex() != nullptr)
                    this->next = new Stiva(meciuri->getNex(), type);

                ec1->setPoe(ec1->getPl(), ec1->getNr());
                this->e = ec1;
            }  
        }
        break;*/
    default:
        break;
    }
}


