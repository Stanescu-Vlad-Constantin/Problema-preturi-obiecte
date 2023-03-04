# Problema-preturi-obiecte
Ați fost angajați să descoperiți care este prețul unor obiecte din diferite case. După un studiu amănunțit, ați făcut o listă cu aceste obiecte și cu prețul lor. În diferite case care se află într-un oraș, pe o stradă și la un anumit număr există un număr de obiecte de valoare. Voi trebuie să calculați care este prețul total al obiectelor din casele care se află pe aceeași stradă și în același oraș.

Cerințe pentru punctaj maxim
Să se creeze o clasă cu numele Object cu următoarele specificații:
- clasa trebuie să conțină 2 atribute private numite valuable și price, primul de tip string, iar al doilea număr fracționar pe simplă precizie;
- clasa trebuie să conțină un constructor public cu 2 parametrii care să inițializeze atributele valuable și price cu valorile specificate;
- clasa trebuie să conțină 2 metode publice fără niciun parametru numite getValuable și getPrice. Acestea trebuie să întoarcă valorile atributelor object, respectiv price. Tipul de dată returnat al metodelor trebuie să îl deduceți voi.

Să se creeze o clasă cu numele House cu următoarele specificații:
- clasa trebuie să conțină 3 atribute private numite street, city și number, primele 2 să fie de tip string, iar al treilea să fie număr întreg fără semn pe 32 de biți;
- clasa trebuie să conțină un atribut privat numit valuables, acesta fiind un std::vector de obiecte de tipul clasei Object;
- clasa trebuie să conțină un constructor public cu 3 parametrii care să inițializeze atributele street, city și number cu valorile specificate;
- clasa trebuie să conțină 3 metode publice fără niciun parametru numite getStreet, getCity și getNumber. Acestea trebuie să întoarcă strada, orașul și numărul casei. Tipul de dată returnat al metodelor trebuie să îl deduceți voi;
- clasa trebuie să conțină o metodă publică fără niciun parametru numită getValuablesSize, care trebuie să întoarcă dimensiunea vectorului valuables. Tipul de dată returnat trebuie să fie un număr întreg fără semn pe 32 de biți;
- clasa trebuie să conțină o metodă publică numită getValuable cu un parametru de tip întreg pe 32 de biți, care trebuie să întoarcă obiectul din vectorul valuables aflat la indexul specificat ca argument. Tipul de dată returnat trebuie să fie un obiect de tip Object;
- clasa trebuie să conțină o metodă publică numită add, care nu întoarce nimic și doar va introduce un obiect de tip Object în vectorul valuables. Evident, această metodă trebuie să ia un singur parametru, obiectul de tip Object care trebuie introdus.

Se va crea o funcție numită getTotalPrice, care va întoarce suma totală a obiectelor de valoare dintr-o anumită casă. Această funcție va trebui să returneze un număr fracționar pe simplă precizie, iar ca parametru va trebui să primească un obiect de tipul House.

ATENȚIE! Ambele clase trebuie să aibă definite și un constructor cu 0 parametrii care să nu facă nimic.

Date de intrare 
Se vor citi până la EOF linii de forma <street> <city> <house_number> <N> <valuable_1> <price_1> <valuable_2> <price_2> ... <valuable_N> <price_N>, care vor fi datele pentru o singură casă. Astfel, <street> este numele străzii, <city> este numele orașului, <house_number> este numărul casei, <N> este numărul de obiecte de valoare din acea casă, iar apoi vom avea N obiecte de valoare de forma <valuable_1> <price_1>, unde <valuable_1> este numele obiectului de valoare și <price_1> este prețul obiectului. Liniile vor fi separate prin caracterul newline (\n). Tipurile de date ale acestor date sunt specificate mai sus. Numele străzii, orașul și numele obiectelor vor fi întotdeauna formate dintr-un singur cuvânt.

Date de ieșire 
La ieșire se va afișa suma tuturor obiectelor de valoare din casele aflate pe aceeași stradă și în același oraș în formatul <street> <city> - <total_price>, unde <street> este numele străzii, <city> este numele orașului, iar <total_price> este prețul total. Liniile se vor sorta lexicografic în funcție de numele străzii. Liniile vor fi separate prin caracterul newline (\n)
