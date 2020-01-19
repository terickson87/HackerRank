
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

struct Attribute {
   std::string m_Name;
   std::string m_Value;
   Attribute()
      : m_Name(""), m_Value("") {}
   Attribute(std::string name)
      : m_Name(name), m_Value("") {}
   Attribute(std::string name, std::string value)
      : m_Name(name), m_Value(value) {}
};

class Tag {
   private:
   std::list<Attribute> m_AttributeList;
   std::string m_TagName;
   std::shared_ptr<Tag> m_Parent;
   /* Tag(const Tag& other) {}
   Tag& operator=(const Tag& other) {return *this;} */

   public:
   Tag() : m_AttributeList(), m_TagName(""), m_Parent(nullptr) { }
   ~Tag() {}

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

   std::list<Attribute> getAttributeList() const {return m_AttributeList;}
   std::string getTagName() const {return m_TagName;}
   std::shared_ptr<Tag> getParent() const {return m_Parent;}
   std::list<Attribute>::iterator findAttribute(Attribute& attribute) const {
      bool hasSameAttributeName(Attribute pred_attribute) {
         if (pred_attribute.m_Name == attribute.m_Name) {
            return true;
         } else {
            return false;
         }
      }
      return std::find_if(m_AttributeList.cbegin, m_AttributeList.cend, attribute);
   }

   void setAttributeList(const std::list<Attribute>& attributeList) {m_AttributeList=attributeList;}
   void pushAttribute(const Attribute attribute) {m_AttributeList.push_back(attribute);}
   void setTagName(const std::string& tagName) {m_TagName=tagName;}
   void setParent(std::shared_ptr<Tag> parent) {m_Parent=parent;}
};

void getAttributes(std::istringstream& iss, Tag& thisTag) {
   std::string thisWord;
   std::string attributeName;
   std::string attributeValue;

   iss >> thisWord;
   const int END_FLAG = 1;
   const int NOT_END_FLAG = 0;
   int endFlag = NOT_END_FLAG;
   
   while (">" != thisWord && END_FLAG != endFlag) {
      attributeName = thisWord;

      iss >> thisWord;
      assert("=" == thisWord);

      iss >> thisWord;
      if ('>' == thisWord.back()) {
         endFlag = 1;
         thisWord.pop_back();
      }
      attributeValue = thisWord;

      Attribute attribute(attributeName, attributeValue);
      thisTag.pushAttribute(attribute);
   }
}

void processLine(std::istream& localCin, std::list<std::shared_ptr<Tag>>& parentList) {
   std::string thisLine;
   char thisChar;

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
   getAttributes(iss, thisTag);
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
