#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Item
{
private:
    string m_object;
    float m_price;
public:
    Item()
    {
        m_object="NULL";
        m_price = 0;
    }
    Item(string o,float p)
    {
        m_object=o;
        m_price=p;
    }

    string getObject()
    {
        return m_object;
    }

    float getPrice()
    {
        return m_price;
    }
};

class Room
{
private:
    uint32_t m_number;
    vector<Item> m_valuables;
public:
    Room()
    {
        m_number=0;
    };
    Room(uint32_t n)
    {
        m_number=n;
    }

    uint32_t getNumber()
    {
        return m_number;
    }

    uint32_t getValuablesSize()
    {
        return m_valuables.size();
    }

    Item getValuable(uint32_t index)
    {
        return m_valuables.at(index);
    }

    void add(Item adaugat)
    {
        m_valuables.push_back(adaugat);
    }

    float getRoomPrice()
    {
        float suma=0;
        int numar=getValuablesSize();
        for(int i=0;i<numar;i++)
            suma += getValuable(i).getPrice();
        return suma;
    }
};

class Hotel
{
private:
    string m_name;
    string m_street;
    string m_city;
    vector<Room> m_rooms;
public:
    Hotel()
    {
        m_street="NULL";
        m_city="NULL";
        m_name="NULL";
    };
    Hotel(string s,string c,string nume)
    {
        m_street=s;
        m_city=c;
        m_name=nume;
    }

    string getStreet()
    {
        return m_street;
    }

    string getCity()
    {
        return m_city;
    }

    string getName()
    {
        return m_name;
    }

    uint32_t getRoomsSize()
    {
        return m_rooms.size();
    }

    Room getRoom(uint32_t index)
    {
        return m_rooms.at(index);
    }

    void add(Room adaugat)
    {
        m_rooms.push_back(adaugat);
    }

    float getHotelPrice()
    {
        float suma=0;
        int numar=getRoomsSize();
        for(int i=0;i<numar;i++)
            suma += getRoom(i).getRoomPrice();
        return suma;
    }
};

int main()
{
    Hotel v[1000];
    Item v1[1000];
    int n=0;
    vector<string> strazi;
    int nr_strazi = 0;
    while(!cin.eof())
    {
        char nume[30];
        float pret;
        int nr;
        char strada[30],oras[30],nume_hotel[30];
        uint32_t numar_camera;
        cin>>strada;
        cin>>oras;
        cin>>nume_hotel;
        cin>>numar_camera;
        Hotel *h;
        h=new Hotel(strada,oras,nume_hotel);
        v[n]=*h;
        cin>>nr;
        for(int i=0;i<nr;i++)
        {
            cin>>nume;
            cin>>pret;
            Item *obj;
            obj = new Item(nume,pret);
            v1[n].add(*obj);
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
            total_valuables.at(i) += v[j].getHotelPrice();
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
