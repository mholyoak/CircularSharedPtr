#include <iostream>
#include <memory>

class OwnShareOne;
class OwnShareTwo;

class OwnShareOne
{
public:
    OwnShareOne()
    {
        std::cout << "Construct OwnShareOne" << std::endl;
    }

    void setShare(const std::shared_ptr<OwnShareTwo>& shareTwo)
    {
        shareTwo_ = shareTwo;
    }

    ~OwnShareOne()
    {
        std::cout << "Destruct OwnShareOne" << std::endl;
    }

private:
    std::shared_ptr<OwnShareTwo> shareTwo_;
};

class OwnShareTwo
{
public:
    OwnShareTwo(const std::shared_ptr<OwnShareOne>& shareOne):
            shareOne_(shareOne)
    {
        std::cout << "Construct OwnShareTwo" << std::endl;
    }

    ~OwnShareTwo()
    {
        std::cout << "Destruct OwnShareTwo" << std::endl;
    }

private:
    std::shared_ptr<OwnShareOne> shareOne_;
};

int main() {
    std::cout << "CircularSharedPtr" << std::endl;

    auto shareOne = std::make_shared<OwnShareOne>();
    auto shareTwo = std::make_shared<OwnShareTwo>(shareOne);
    shareOne->setShare(shareTwo);

    return 0;
}
