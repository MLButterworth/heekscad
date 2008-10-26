// GripperSelTransform.h

#if !defined GripperSelTransform_HEADER
#define GripperSelTransform_HEADER

#include "Gripper.h"

class GripperSelTransform:public Gripper{
public:
	double m_from[3];
	double m_last_from[3];
	double m_initial_grip_pos[3];
	std::list<HeeksObj *> m_items_marked_at_grab;

	GripperSelTransform(const gp_Pnt& pos, EnumGripperType gripper_type);

	// HeeksObj's virtual functions
	HeeksObj *MakeACopy(void)const{ return new GripperSelTransform(*this);}

	// virtual functions
	void MakeMatrix(const double* from, const double* to, const double* object_m, gp_Trsf& mat);

	//Gripper's virtual functions
	void OnGripperMoved( double* from, const double* to );
	bool OnGripperGrabbed(const std::list<HeeksObj*>& list, bool show_grippers_on_drag, double* from);
	void OnGripperReleased(const double* from, const double* to);
};

#endif
