
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
   std::list<std::string> m_AttributeList;
   std::string m_TagName;
   std::shared_ptr<Tag> m_Parent;
   Tag(const Tag& other)
   : m_AttributeList(other.getAttributeList()),
   m_TagName(other.getTagName()),
   m_Parent(other.getParent()) { }

   Tag& operator=(const Tag& other) {
      if (this != &other) {
         m_AttributeList = other.getAttributeList();
         m_TagName = other.getTagName();
         m_Parent = other.getParent();
         return *this;
      }
   }
   /* Tag(const Tag& other) {}
   Tag& operator=(const Tag& other) {return *this;} */

   public:
   Tag() : m_AttributeList(), m_TagName(""), m_Parent(nullptr) { }
   ~Tag() {}

   std::list<std::string> getAttributeList() const {return m_AttributeList;}
   std::string getTagName() const {return m_TagName;}
   std::shared_ptr<Tag> getParent() const {return m_Parent;}

   void setAttribute(const std::list<std::string>& attributeList) {m_AttributeList=attributeList;}
   void setTagName(const std::string& tagName) {m_TagName=tagName;}
   void setParent(std::shared_ptr<Tag> parent) {m_Parent=parent;}
};

void processLine(std::istream& localCin, std::list<std::shared_ptr<Tag>>& parentList) {
   std::string thisLine;
   char thisChar;
   std::string thisWord;

   std::getline(std::cin, thisLine);
   localCin.get(thisChar);
   assert('<' == thisChar);

   Tag thisTag;
   std::shared_ptr<Tag> pTag( new Tag() );
   pTag->setParent(parentList.back());
   parentList.push_back(pTag);

   std::istringstream iss (thisLine);
   std::string tag;
   iss >> tag;
   thisTag.setTagName(tag);

   iss >> thisWord;
   if (thisWord == ">") {
      /* code */
   }
   

   std::ostringstream oss;

   


   std::string attribute;
   

}

int main() {
   unsigned int numberOfTagLines;
   unsigned int numberOfQueries;
   std::cin >> numberOfTagLines;
   std::cin >> numberOfQueries;
   
   std::string thisLine;
   std::list<std::shared_ptr<Tag>> parentList;
   parentList.push_back(nullptr);
   for (size_t i = 0; i < numberOfTagLines; ++i) {
      processLine(std::cin, parentList);
   }
   
   return 0;
}
