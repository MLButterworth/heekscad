// Property.h

// Base class for all Properties

#if !defined Property_HEADER
#define Property_HEADER

enum{
	InvalidPropertyType,
	StringPropertyType,
	DoublePropertyType,
	IntPropertyType,
	VertexPropertyType,
	ChoicePropertyType,
	ColorPropertyType,
	CheckPropertyType,
	ListOfPropertyType,
	TrsfPropertyType
};

#include <vector>

class Property{
public:
	bool m_highlighted;

	Property(bool highlighted = false):m_highlighted(highlighted){}
	virtual ~Property(){}

	virtual int get_property_type(){return InvalidPropertyType;}
	virtual bool property_editable()const = 0;
	virtual Property *MakeACopy(void)const = 0;
	virtual void CallSetFunction()const = 0;
	virtual const wxChar* GetShortString(void)const{return _("Unknown Property");}
};

#endif
