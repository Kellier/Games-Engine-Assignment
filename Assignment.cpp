#include "Assignment.h"
#include "Content.h"
#include "VectorDrawer.h"
#include "LazerBeam.h"
#include "FountainEffect.h"
#include "Utils.h"
#include <btBulletDynamicsCommon.h>
#include "PhysicsFactory.h"
#include "PhysicsController.h"
#include "Sphere.h"
#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "GravityController.h"

using namespace BGE;

Assignment::Assignment(void)
{
	elapsed = 10000;
	turnRate = glm::half_pi<float>(); 
}

Assignment::~Assignment(void)
{

}

//Initialise all the variables
bool Assignment::Initialise()
{
	scale = 2.0f;
	angle1, angle2 = 45.0f;
	pos = glm::vec3(0.0f, 10.0f, 0.0f);

	//Create ground physics for the object to appear on the ground
	physicsFactory->CreateGroundPhysics();
	std::shared_ptr<GameComponent> ground = make_shared<Ground>();
	Attach(ground);
	Game::dynamicsWorld->setGravity(btVector3(0, -10, 0));

	//Define Basic Shape
	shared_ptr<PhysicsController> car = CreateCar(pos);

	Game::Initialise();

	//Define position of the camera
	camera->transform->position = glm::vec3(20, 25, 30);
	return true;
}

void Assignment::Update(float timeDelta)
{
	//Attempt at changing the angle of the car so movement is possible if it fell on its side
	if (keyState[SDL_SCANCODE_L])
	{
		angle1 = angle1 + 45.0f;
		angle2 = angle2 + 45.0f;
	}

	Game::Update(timeDelta);
}

shared_ptr<PhysicsController> Assignment::CreateCar(glm::vec3 position)
{
	//Body of Car with its width, height, depth, position and angle
	std::shared_ptr<PhysicsController> body = physicsFactory->CreateBox(scale * 1.5f, scale, scale * 3, glm::vec3(0, 5, 0), glm::angleAxis(angle1, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel1 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel2 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel3 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel4 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel5 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel6 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel7 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));
	//Wheel of Car with its radius, height, position and angle 
	std::shared_ptr<PhysicsController> wheel8 = physicsFactory->CreateSphere(scale - 1.0f, glm::vec3(4, 6, 7), glm::angleAxis(angle2, glm::vec3(0, 1, 0)));

	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel1Hinge = new btHingeConstraint(*body->rigidBody, *wheel1->rigidBody, btVector3(3, 0, 4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel2Hinge = new btHingeConstraint(*body->rigidBody, *wheel2->rigidBody, btVector3(-3, 0, 4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel3Hinge = new btHingeConstraint(*body->rigidBody, *wheel3->rigidBody, btVector3(3, 0, -4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel4Hinge = new btHingeConstraint(*body->rigidBody, *wheel4->rigidBody, btVector3(-3, 0, -4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel5Hinge = new btHingeConstraint(*body->rigidBody, *wheel5->rigidBody, btVector3(3, 4, 4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel6Hinge = new btHingeConstraint(*body->rigidBody, *wheel6->rigidBody, btVector3(3, 4, -4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel7Hinge = new btHingeConstraint(*body->rigidBody, *wheel7->rigidBody, btVector3(-3, 4, 4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);
	//Hinge for Wheel allowing proper positioning on the body of the car. This occurs in the first btVector3
	Wheel8Hinge = new btHingeConstraint(*body->rigidBody, *wheel8->rigidBody, btVector3(-3, 4, -4), btVector3(0, 2, 0), btVector3(0, 1, 0), btVector3(0, 1, 0), true);

	//Set the limits of the hinges so proper movement can be achieved
	Wheel1Hinge->setLimit(0, 5);
	Wheel2Hinge->setLimit(0, 5);
	Wheel3Hinge->setLimit(0, 5);
	Wheel4Hinge->setLimit(0, 5);
	Wheel5Hinge->setLimit(0, 5);
	Wheel6Hinge->setLimit(0, 5);
	Wheel7Hinge->setLimit(0, 5);
	Wheel8Hinge->setLimit(0, 5);

	//Set the starting angle and the motion of the hinges
	Wheel1Hinge->enableAngularMotor(true, 90, 100);
	Wheel2Hinge->enableAngularMotor(true, 90, 100);
	Wheel3Hinge->enableAngularMotor(true, 90, 100);
	Wheel4Hinge->enableAngularMotor(true, 90, 100);
	Wheel5Hinge->enableAngularMotor(true, 90, 100);
	Wheel6Hinge->enableAngularMotor(true, 90, 100);
	Wheel7Hinge->enableAngularMotor(true, 90, 100);
	Wheel8Hinge->enableAngularMotor(true, 90, 100);
	
	//Add the constraints to the Game class
	Game::dynamicsWorld->addConstraint(Wheel1Hinge);
	Game::dynamicsWorld->addConstraint(Wheel2Hinge);
	Game::dynamicsWorld->addConstraint(Wheel3Hinge);
	Game::dynamicsWorld->addConstraint(Wheel4Hinge);
	Game::dynamicsWorld->addConstraint(Wheel5Hinge);
	Game::dynamicsWorld->addConstraint(Wheel6Hinge);
	Game::dynamicsWorld->addConstraint(Wheel7Hinge);
	Game::dynamicsWorld->addConstraint(Wheel8Hinge);

	return body;
}