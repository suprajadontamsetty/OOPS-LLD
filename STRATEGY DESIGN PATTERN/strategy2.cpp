#include<iostream>
using namespace std;

class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Walking normally..." << endl; 
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Cannot walk." << endl; 
    }
};

class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

class NormalTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Talking normally..." << endl; 
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Cannot talk." << endl; 
    }
};

class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};






class Robot{
  protected:
  WalkableRobot* walkBehaviour;
  TalkableRobot* talkBehaviour;
  FlyableRobot* flyableBehaviour;

  public:
  Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f){
    this->walkBehaviour=w;
    this->talkBehaviour=t;
    this->flyableBehaviour=f;
  }

  void walk() {
    walkBehaviour->walk();

  }

  void talk() {
    talkBehaviour->talk();
  }

  void fly(){
    flyableBehaviour->fly();
  }

  virtual void projection()=0;
};

class CompanionRobot: public Robot {
 public:
 CompanionRobot(WalkableRobot*w, TalkableRobot*t, FlyableRobot*f)
 : Robot(w,t,f){}

 void projection() override{
    cout<<"Displaying friendly conpanion features..."<<endl;
 }

};

class WorkerRobot:public Robot{
  public:
  WorkerRobot(WalkableRobot*w, TalkableRobot*t, FlyableRobot*f)
  :Robot(w,t,f){}

  void projection() override{
    cout<<"Displaying worker efficiency states..."<<endl;
  }
};

int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}