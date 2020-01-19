
// https://www.hackerrank.com/challenges/attribute-parser/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <list>
#include <string>
#include <sstream>
#include <cassert>

class Tag {
   private:
   std::string m_Attribute;
   std::string m_TagName;
   Tag* m_Parent;

   public:
   Tag() : m_Attribute(""), m_TagName(""), m_Parent(nullptr) { }
   Tag(const Tag& other)
   : m_Attribute(other.getAttribute()),
   m_TagName(other.getTagName()),
   m_Parent(other.getParent()) { }
   Tag& operator=(const Tag& other) {
      if (this != &other) {
         m_Attribute = other.getAttribute();
         m_TagName = other.getTagName();
         m_Parent = other.getParent();
         return *this;
      }
   }
   ~Tag();

   std::string getAttribute() const {return m_Attribute;}
   std::string getTagName() const {return m_TagName;}
   Tag* getParent() const {return m_Parent;}

   void setAttribute(const std::string& attribute) {m_Attribute=attribute;}
   void setTagName(const std::string& tagName) {m_Attribute=tagName;}
   void setParent(Tag* const parent) {m_Parent=parent;}
};

void processLine(std::istream& localCin, std::list<Tag*>& parentList) {
   std::string thisLine;
   std::getline(std::cin, thisLine);
   char thisChar;
   localCin.get(thisChar);
   assert('<' == thisChar);

   std::istringstream iss (thisLine);
   std::string tag;
   std::string attribute;
}

int main() {
   unsigned int numberOfTagLines;
   unsigned int numberOfQueries;
   std::cin >> numberOfTagLines;
   std::cin >> numberOfQueries;
   
   std::string thisLine;
   std::list<Tag*> parentList;
   parentList.push_back(nullptr);
   for (size_t i = 0; i < numberOfTagLines; ++i) {
      processLine(std::cin, parentList);
   }
   
   return 0;
}
