#include <iostream>
#include <map>
#include <string>
int main()
{
    std::map<int, std::string> db;
    db.insert({ 1995, "ITMO" });
    db.insert({ 1996, "SPbSU" });
    db.insert({ 1997, "SPbSU" });
    db.insert({ 1998, "ITMO" });
    db.insert({ 1999, "ITMO" });
    db.insert({ 2000, "SPbSU" });
    db.insert({ 2001, "ITMO" });
    db.insert({ 2002, "ITMO" });
    db.insert({ 2003, "ITMO" });
    db.insert({ 2004, "ITMO" });
    db.insert({ 2005, "ITMO" });
    db.insert({ 2006, "PetrSU, ITMO" });
    db.insert({ 2007, "SPbSU" });
    db.insert({ 2008, "SPbSU" });
    db.insert({ 2009, "ITMO" });
    db.insert({ 2010, "ITMO" });
    db.insert({ 2011, "ITMO" });
    db.insert({ 2012, "ITMO" });
    db.insert({ 2013, "SPbSU" });
    db.insert({ 2014, "ITMO" });
    db.insert({ 2015, "ITMO" });
    db.insert({ 2016, "ITMO" });
    db.insert({ 2017, "ITMO" });
    db.insert({ 2018, "SPbSU" });
    db.insert({ 2019, "ITMO" });
    int y; std::cin >> y;
    std::cout << db[y] << std::endl;
}
