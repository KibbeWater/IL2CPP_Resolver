## IL2CPP Resolver
A run-time API resolver for IL2CPP Unity.

[External Version(Rework WIP)](https://github.com/extremeblackliu/IL2CPP_Resolver_External) | [(Old) Pre-HeaderOnly Version](https://github.com/sneakyevil/IL2CPP_Resolver/tree/old_nonheader)

### Using IL2CPP Resolver in External Projects

#### Method 1: Using FetchContent (Recommended)

Add the following to your CMakeLists.txt:

```cmake
include(FetchContent)

FetchContent_Declare(
    IL2CPP_Resolver
    GIT_REPOSITORY https://github.com/sneakyevil/IL2CPP_Resolver.git
    GIT_TAG main  # Or specify a specific tag/commit
)

FetchContent_MakeAvailable(IL2CPP_Resolver)

# Link your target with IL2CPP_Resolver (using either namespace works)
add_executable(YourApp main.cpp)
target_link_libraries(YourApp PRIVATE IL2CPP_Resolver::IL2CPP_Resolver)
# Alternatively, you can use:
# target_link_libraries(YourApp PRIVATE resolver::IL2CPP_Resolver)
```

That's it! All headers will be automatically available to your target.

#### Method 2: Using an Installed Version

If you've installed IL2CPP_Resolver on your system:

```cmake
find_package(IL2CPP_Resolver REQUIRED)

add_executable(YourApp main.cpp)
target_link_libraries(YourApp PRIVATE IL2CPP_Resolver::IL2CPP_Resolver)
# Alternatively, you can use:
# target_link_libraries(YourApp PRIVATE resolver::IL2CPP_Resolver)
```

### Quick Example
```cpp
#include <IL2CPP_Resolver.h>

void SomeFunction()
{
    IL2CPP::Initialize(); // This needs to be called once!

    Unity::CGameObject* m_Local = Unity::GameObject::Find("LocalPlayer");
    Unity::CComponent* m_LocalData = m_Local->GetComponent("PlayerData");
    m_LocalData->SetMemberValue<bool>("CanFly", true);
}
```

### Registering OnUpdate Callback
```cpp
void OurUpdateFunction()
{
    // Your special code...
}

void OnLoad()
{
    IL2CPP::Initialize();

    IL2CPP::Callback::Initialize();
    IL2CPP::Callback::OnUpdate::Add(OurUpdateFunction);
}
```

More: https://sneakyevil.gitbook.io/il2cpp-resolver/
