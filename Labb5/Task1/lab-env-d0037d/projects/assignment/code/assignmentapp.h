//------------------------------------------------------------------------------
/**
	Application class used for Assignment applications.
	Based on 2D app
	
	(C) 2015-2017 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"

class Shape;

namespace Assignment
{
class AssignmentApp : public App2D::BaseApp
{
public:
	std::vector<Shape*> renderQueue;

	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();

	/// initialize, create shapes etc
	void Setup();

	/// update app, draw lines etc
	void Update();

	/// line drawing function
	static void DrawLine(const LineData & line);

	/// copies renderQueue
	void ClearByShape(const type_info & type);

	/// key events
	void KeyEvent(int key, int action, int modifier);

private:
	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);

};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}
} // namespace Assignment