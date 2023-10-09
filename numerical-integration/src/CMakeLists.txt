ADD_LIBRARY(integration STATIC
        integration/simpsons-rule.c
        integration/left-riemann-sum.c
        integration/middle-riemann-sum.c)
TARGET_INCLUDE_DIRECTORIES(integration
        PUBLIC ../include)

ADD_LIBRARY(runges-rule STATIC
        runges-rule/runges-rule.c)
TARGET_INCLUDE_DIRECTORIES(runges-rule
        PUBLIC ../include)