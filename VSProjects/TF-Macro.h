//Return boolean, true if global variable found
#define tf_AppWideVariable_exist(VariableName) site->FlowEngine->AppWideVariables->ContainsKey(VariableName)

//Return object containing app wide's variable value (Value casting is required)
#define tf_AppWideVariable_Cast(VariableName) site->FlowEngine->AppWideVariables[VariableName]->Value

//Return String containing Site Name
#define tf_SiteName() site->Name

//Return string containing flow name
#define tf_FlowName() site->Flow->Name

//Return boolean, true if flow variable found
#define tf_FlowVariable_exist(VariableName) site->Variables->ContainsKey(VariableName)

//Return object containing flow's variable value (Value casting is required)
#define tf_FlowVariable_Cast(VariableName) site->Variables[VariableName][site]->Value

//Return boolean, true if flow condition found
#define tf_FlowCondition_exist(ConditionName) site->Conditions->ContainsKey(ConditionName)

//Return object containing flow's condition value (Value casting is required)
#define tf_FlowCondition_Cast(ConditionName) site->Conditions[ConditionName][site]->Value

//Return current Controlitem name
#define tf_ControlItem_Name() ((ControlItem^)site->CurrentFlowItem)->Name

//Return current Controlitem
#define tf_ControlItem() ((ControlItem ^)site->CurrentFlowItem)

//Return boolean, true if condition is exist
#define tf_ControlItemCondition_exist(ConditionName) ((ControlItem ^)site->CurrentFlowItem)->Conditions->ContainsKey(ConditionName)

//Return object containing current controlitem's condition value (Value casting is required)
#define tf_ControlItemCondition_Cast(ConditionName) ((ControlItem ^)site->CurrentFlowItem)->Conditions[ConditionName][site]->Value

//Return current testitem Name
#define tf_TestItem_Name() ((TestItem^)site->CurrentFlowItem)->Name

//Return current testitem display Name
#define tf_TestItem_DisplayName() ((TestItem^)site->CurrentFlowItem)->DisplayName

//Return current testitem
#define tf_TestItem() ((TestItem^)site->CurrentFlowItem)

//Return boolean, true if condition is exist
#define tf_TestItemCondition_exist(ConditionName) ((TestItem^)site->CurrentFlowItem)->Conditions->ContainsKey(ConditionName)

//Return object containing testitem's condition value (Value casting is required)
#define tf_TestItemCondition_Cast(ConditionName) ((TestItem^)site->CurrentFlowItem)->Conditions[ConditionName][site]->Value

//Return number of test parameter in current testItem
#define tf_TestParameter_Count() ((TestItem ^)site->CurrentFlowItem)->TestParameters->Count

//Return test parameter name by test parameter index
#define tf_TestParameter_Name(TPIndex) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPIndex]->Name

//Return test parameter display name by test parameter index
#define tf_TestParameter_DisplayName(TPIndex) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPIndex]->DisplayName

//Return test parameter name by test parameter index
#define tf_TestParameter_FullName(TPIndex) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPIndex]->FullName

//Return (current testitem) specified test parameter
#define tf_TestParameter(TPName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPName]

//Return Max Limit of test parameter in current test Item
#define tf_TestParameter_MaxLimit(TPName) ((TestItem ^)site->CurrentFlowItem)->TestParameters[TPName]->Limit[site]->LimitMax

//Return Max Limit of test parameter in current test Item
#define tf_TestParameter_MinLimit(TPName) ((TestItem ^)site->CurrentFlowItem)->TestParameters[TPName]->Limit[site]->LimitMin

//Return ConditionCollection
#define tf_TPConditions_List(TPName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPName]->Conditions

//Return Condition Count
#define tf_TPConditions_Count(TPName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPName]->Conditions->Count

//Return boolean, true if condition is exist
#define tf_TPCondition_exist(TPName, ConditionName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPName]->Conditions->ContainsKey(ConditionName)

//Return (current testitem) test parameter's condition value (Value casting is required)
#define tf_TPCondition_Cast(TPName, ConditionName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TPName]->Conditions[ConditionName][site]->Value

//Return (current testitem) test parameter's low limit (Value casting is required)
#define tf_TPLowLimit_Cast(TestParameterName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TestParameterName]->Limit[site]->LimitMin

//Return (current testitem) test parameter's high limit (Value casting is required)
#define tf_TPHighLimit_Cast(TestParameterName) ((TestItem^)site->CurrentFlowItem)->TestParameters[TestParameterName]->Limit[site]->LimitMax

//Set test parameter's run result
#define tf_SetResult(TPName, Result) site->SetResult(((TestItem^)site->CurrentFlowItem)->TestParameters[TPName], Result )

//Set test parameter's run result
#define tf_SetResult_UUTOffset(TPName, Result, uutOffset) site->SetResult(((TestItem^)site->CurrentFlowItem)->TestParameters[TPName], Result,  site->UUTOffsetResolver->UUTOffsets[uutOffset])

//Set test parameter's run result with defined prefix
#define tf_SetResultPrefix(TPName, Result, AemulusUnitPrefix) site->SetResult(((TestItem^)site->CurrentFlowItem)->TestParameters[TPName], Result, AemulusUnitPrefix)

//Return total test parameter count for current testitem
#define tf_TPCount() ((TestItem^)site->CurrentFlowItem)->TestParameters->Count

//Set test parameter's run result
#define tf_SetResultnTestTime(TPName, Result, TestTime) site->SetResult(((TestItem^)site->CurrentFlowItem)->TestParameters[TPName], Result, TestTime)

//Set test parameter's run result with uut offsets
#define tf_SetResultnTestTime_byUUTOffsetName(TPName, Result, TestTime, UUTOffsetName) site->SetResult(((TestItem^)site->CurrentFlowItem)->TestParameters[TPName], Result, TestTime, site->UUTOffsetResolver->UUTOffsets[UUTOffsetName])