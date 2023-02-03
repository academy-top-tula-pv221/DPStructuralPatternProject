#include <iostream>

//#include "Adapter.h"
//void AdapterExample()
//{
//    Client client;
//    client.ClientMethod();
//}

//#include "StrategyGame.h"
//void BridgeExample()
//{
//    StrategyGame game(new KeyboardImpl());
//
//    game.Setup();
//    game.Process();
//
//    cout << "Game Over!\n";
//}

/*
#include "Composite.h"
void CompositeExample()
{
    srand(time(nullptr));

    vector<Factory*> factories;
    factories.push_back(new InfantryFactory());
    factories.push_back(new ArcherFactory());
    factories.push_back(new CavalryFactory());

    Unit* legion1 = new UnitGroup("Legion 1");
    for (int i = 0; i < 10; i++)
    {
        auto legion = (UnitGroup*)legion1;
        auto unit = factories[rand() % 3]->CreateUnit();
        legion->Add(unit);
    }

    Unit* legion2 = new UnitGroup("Legion 2");
    for (int i = 0; i < 5; i++)
    {
        auto legion = (UnitGroup*)legion2;
        auto unit = factories[rand() % 3]->CreateUnit();
        legion->Add(unit);
    }

    Unit* falanga1 = new UnitGroup("Falanga 1");
    for (int i = 0; i < 3; i++)
    {
        auto legion = (UnitGroup*)falanga1;
        auto unit = factories[rand() % 3]->CreateUnit();
        legion->Add(unit);
    }

    ((UnitGroup*)legion1)->Add(falanga1);

    Unit* armyPtr = new UnitGroup("Army");
    auto army = (UnitGroup*)armyPtr;
    army->Add(legion1);
    army->Add(legion2);
    army->Add(factories[rand() % 3]->CreateUnit());
    army->Add(factories[rand() % 3]->CreateUnit());

    cout << army->ToString() << "\n";
}
*/

//
//#include "Decorator.h"
//void DecoratorExample()
//{
//    IMessage* messageWathup = new EmailMessage();
//    messageWathup->Send();
//    cout << "\n";
//
//    messageWathup = new FileMessage(messageWathup, "photoFoma.jpg");
//    messageWathup->Send();
//    cout << "\n";
//
//    messageWathup = new ContactMessage(messageWathup, "Afonya 123-45-67");
//    messageWathup->Send();
//    cout << "\n";
//
//    messageWathup = new FileMessage(messageWathup, "photoKlyazma.jpg");
//    messageWathup->Send();
//    cout << "\n";
//}

//
//#include "Facade.h"
//void FacadeExample()
//{
//    VisualStudioFacade* vs = new VisualStudioFacade(
//        new TextEditor(),
//        new Compiller(),
//        new Debugger(),
//        new RunTime()
//    );
//
//    vs->Start();
//    vs->Finish();
//}

//
//#include "Flyweight.h"
//void FlyweightExample()
//{
//    BookBad b1("War and Piece", "Leo", "Tolstoy");
//    BookBad b2("Anna Karenina", "Leo", "Tolstoy");
//    BookBad b3("Sevastopol stories", "Leo", "Tolstoy");
//
//    Author author("Leo", "Tolstoy");
//    BookGood book1("War and Piece", &author);
//    BookGood book2("Anna Karenina", &author);
//    BookGood book3("Sevastopol stories", &author);
//
//    cout << "\n Hoses:\n";
//    double longitude = 37.65;
//    double latitude = 55.65;
//
//    HouseFactory factory;
//    for (int i = 0; i < 5; i++)
//    {
//        House* house = factory.GetHouse("Panel");
//        if (house != nullptr)
//            house->Build(longitude, latitude);
//        longitude += 0.1;
//        latitude += 0.1;
//    }
//
//    for (int i = 0; i < 5; i++)
//    {
//        House* house = factory.GetHouse("Brick");
//        if (house != nullptr)
//            house->Build(longitude, latitude);
//        longitude += 0.1;
//        latitude += 0.1;
//    }
//}

int main()
{
    
        

}
