#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
#include "lwm2m_types.h"

class Lwm2mTypesTestSuite : public testing::Test
{
  void SetUp() { }
  void TearDown() { }
};

TEST_F(Lwm2mTypesTestSuite, ResourceType_Strings_are_consistent)
{
    ASSERT_EQ(static_cast<size_t>(AwaStaticResourceType_ObjectLink + 2), Lwm2mCore_GetNumberOfResourceTypeStrings()); // + 1 for invalid=-1, +1 for starting at 0
}

TEST_F(Lwm2mTypesTestSuite, ResourceType_ToString)
{
    EXPECT_STREQ("Invalid", Lwm2mCore_ResourceTypeToString(AwaStaticResourceType_Invalid));
    EXPECT_STREQ("ObjectLink", Lwm2mCore_ResourceTypeToString(AwaStaticResourceType_ObjectLink));
}

TEST_F(Lwm2mTypesTestSuite, ResourceType_FromString)
{
    EXPECT_EQ(AwaStaticResourceType_Invalid, Lwm2mCore_ResourceTypeFromString("Invalid"));
    EXPECT_EQ(AwaStaticResourceType_ObjectLink, Lwm2mCore_ResourceTypeFromString("ObjectLink"));
}
