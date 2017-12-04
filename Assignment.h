#pragma once 
#include "Game.h"
#include "GameComponent.h"

using namespace std;

namespace BGE
{
	class Assignment :
		public Game
	{
	public:
		Assignment(void);
		~Assignment(void);

		shared_ptr<PhysicsController> CreateCar(glm::vec3);

		float turnRate;
		float toRoatate;
		float elapsed;
		bool Initialise();
		void Update(float timeDelta);
		bool slerping;
		glm::quat fromQuaternion;
		glm::quat toQuaternion;
		
		btHingeConstraint * Wheel1Hinge;
		btHingeConstraint * Wheel2Hinge;
		btHingeConstraint * Wheel3Hinge;
		btHingeConstraint * Wheel4Hinge;
		btHingeConstraint * Wheel5Hinge;
		btHingeConstraint * Wheel6Hinge;
		btHingeConstraint * Wheel7Hinge;
		btHingeConstraint * Wheel8Hinge;

		float scale;
		float angle1, angle2;
		glm::vec3 pos;
		float t;
	};
}
