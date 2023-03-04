#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Object
{
private:
    string valuable;
    float price;
public:
    Object()
    {
        valuable="NULL";
        price = 0;
    }
    Object(string v,float p)
    {
        valuable=v;
        price=p;
    }

    string getValuable()
    {
        return valuable;
    }

    float getPrice()
    {
        return price;
    }
};

class House
{
private:
    string street;
    string city;
    uint32_t number;
    vector<Object> valuables;
public:
    House()
    {
        street="NULL";
        city="NULL";
        number=0;
    };
    House(string s,string c,uint32_t nr)
    {
        street=s;
        city=c;
        nr=number;
    }

    string getStreet()
    {
        return street;
    }

    string getCity()
    {
        return city;
    }

    uint32_t getNumber()
    {
        return number;
    }

    uint32_t getValuablesSize()
    {
        return valuables.size();
    }

    Object getValuable(uint32_t index)
    {
        return valuables.at(index);
    }

    void add(Object adaugat)
    {
        valuables.push_back(adaugat);
    }

    float getTotalPrice()
    {
        float suma=0;
        int numar=getValuablesSize();
        for(int i=0;i<numar;i++)
            suma += getValuable(i).getPrice();
        return suma;
    }
};

int main()
{
    House v[1000];
    int n=0;
    vector<string> strazi;
    int nr_strazi = 0;
    while(!cin.eof())
    {
        char nume[30];
        float pret;
        int nr;
        char str[30],oras[30];
        int numar_casa;
        cin>>str;
        cin>>oras;
        cin>>numar_casa;
        House *h;
        h=new House(str,oras,numar_casa);
        v[n]=*h;
        cin>>nr;
        for(int i=0;i<nr;i++)
        {
            cin>>nume;
            cin>>pret;
            Object *obj;
            obj = new Object(nume,pret);
            v[n].add(*obj);
        }
        n++;
        int str_new=1;
        for(int i=0;i<strazi.size();i++)
        {
          if(strazi.at(i).compare(str) == 0)
          str_new = 0;
        }
        if(str_new != 0)
        {
          strazi.push_back(str);
          nr_strazi++;
        }
    }
    n--;
    std::sort(strazi.begin(),strazi.end());

    vector<float> total_valuables(nr_strazi, 0.0);
    for(int i=0;i<nr_strazi;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(strazi.at(i).compare(v[j].getStreet()) == 0)
        {
            total_valuables.at(i) += v[j].getTotalPrice();
        }
      }
      int j=0;
      while (strazi.at(i).compare(v[j].getStreet()) != 0)
      {
        j++;
      }
      cout<<strazi.at(i)<<" "<<v[j].getCity()<<" - ";
      cout<<total_valuables.at(i)<<"\n";
    }
    return 0;
}
