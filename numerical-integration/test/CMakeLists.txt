ADD_EXECUTABLE(integration-test
        integration/main.c)
TARGET_LINK_LIBRARIES(integration-test
        PRIVATE integration
        PRIVATE m)

ADD_EXECUTABLE(runges-rule-test
        runges-rule/main.c)
TARGET_LINK_LIBRARIES(runges-rule-test
        PRIVATE integration
        PRIVATE runges-rule
        PRIVATE m)

ADD_TEST(
        NAME tests-integration-methods
        COMMAND integration-test
)
ADD_TEST(
        NAME tests-runges-rule-methods
        COMMAND runges-rule-test
)