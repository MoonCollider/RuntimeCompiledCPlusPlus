#include "../../RuntimeObjectSystem/ObjectInterfacePerModule.h"

#include "../../RuntimeObjectSystem/IObject.h"
#include "IUpdateable.h"
#include "InterfaceIds.h"
#include <iostream>


class RuntimeObject01 : public TInterface<IID_IUPDATEABLE,IUpdateable>
{
public:
	virtual void Update( float deltaTime )
	{
		std::cout << "Hello!\n";
	}
};

REGISTERCLASS(RuntimeObject01);
