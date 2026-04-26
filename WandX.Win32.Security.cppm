module;

#include <Windows.h>
#include <AclApi.h>
#include <SDDL.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Security.h"

export module WandX.Win32.Security;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Security");

export namespace WandX {
namespace Native {

#pragma region SDDL.h
wapi_ret_true_WAO(ConvertSidToStringSid);
wapi_ret_true_WAO(ConvertStringSidToSid);
wapi_ret_true_WAO(ConvertStringSecurityDescriptorToSecurityDescriptor);
wapi_ret_true_WAO(ConvertSecurityDescriptorToStringSecurityDescriptor);
#pragma endregion

#pragma region SecurityBaseAPI.h
wapi_ret_true(AccessCheck);
wapi_ret_true_WAO(AccessCheckAndAuditAlarm); // AccessCheckAndAuditAlarmA from WinBase.h
wapi_ret_true(AccessCheckByType);
wapi_ret_true(AccessCheckByTypeResultList);
wapi_ret_true_WAO(AccessCheckByTypeAndAuditAlarm); // AccessCheckByTypeAndAuditAlarmA from WinBase.h
wapi_ret_true_WAO(AccessCheckByTypeResultListAndAuditAlarm); // AccessCheckByTypeResultListAndAuditAlarmA from WinBase.h
wapi_ret_true_WAO(AccessCheckByTypeResultListAndAuditAlarmByHandle); // AccessCheckByTypeResultListAndAuditAlarmByHandleA from WinBase.h
wapi_ret_true(AddAccessAllowedAce);
wapi_ret_true(AddAccessAllowedAceEx);
wapi_ret_true(AddAccessAllowedObjectAce);
wapi_ret_true(AddAccessDeniedAce);
wapi_ret_true(AddAccessDeniedAceEx);
wapi_ret_true(AddAccessDeniedObjectAce);
wapi_ret_true(AddAce);
wapi_ret_true(AddAuditAccessAce);
wapi_ret_true(AddAuditAccessAceEx);
wapi_ret_true(AddAuditAccessObjectAce);
wapi_ret_true(AddMandatoryAce);
wapi_ret_true(AddResourceAttributeAce);
wapi_ret_true(AddScopedPolicyIDAce);
wapi_ret_true(AdjustTokenGroups);
wapi_ret_true(AdjustTokenPrivileges);
wapi_ret_true(AllocateAndInitializeSid);
wapi_ret_true(AllocateLocallyUniqueId);
wapi_ret_true(AreAllAccessesGranted);
wapi_ret_direct(AreAnyAccessesGranted);
wapi_ret_true(CheckTokenMembership);
wapi_ret_true(CheckTokenCapability);
wapi_ret_true(GetAppContainerAce);
wapi_ret_true(CheckTokenMembershipEx);
wapi_ret_true(ConvertToAutoInheritPrivateObjectSecurity);
wapi_ret_true(CopySid);
wapi_ret_true(CreatePrivateObjectSecurity);
wapi_ret_true(CreatePrivateObjectSecurityEx);
wapi_ret_true(CreatePrivateObjectSecurityWithMultipleInheritance);
wapi_ret_true(CreateRestrictedToken);
wapi_ret_true(CreateWellKnownSid);
wapi_ret_true(EqualDomainSid);
wapi_ret_true(DeleteAce);
wapi_ret_true(DestroyPrivateObjectSecurity);
wapi_ret_true(DuplicateToken);
wapi_ret_true(DuplicateTokenEx);
wapi_ret_direct(EqualPrefixSid);
wapi_ret_direct(EqualSid);
wapi_ret_true(FindFirstFreeAce);
wapi_ret_true(GetAce);
wapi_ret_true(GetAclInformation);
wapi_ret_true_WAO(GetFileSecurity); // GetFileSecurityA from WinBase.h
wapi_ret_true(GetKernelObjectSecurity);
wapi_ret_true(GetPrivateObjectSecurity);
wapi_ret_true(GetSecurityDescriptorControl);
wapi_ret_true(GetSecurityDescriptorDacl);
wapi_ret_true(GetSecurityDescriptorGroup);
wapi_ret_true(GetSecurityDescriptorOwner);
wapi_ret_true(GetSecurityDescriptorSacl);
wapi_ret_true(GetTokenInformation);
wapi_ret_true(GetWindowsAccountDomainSid);
wapi_ret_true(ImpersonateAnonymousToken);
wapi_ret_true(ImpersonateLoggedOnUser);
wapi_ret_true(ImpersonateSelf);
wapi_ret_true(InitializeAcl);
wapi_ret_true(InitializeSecurityDescriptor);
wapi_ret_true(InitializeSid);
wapi_ret_direct(IsTokenRestricted);
wapi_ret_direct(IsValidAcl);
wapi_ret_direct(IsValidSecurityDescriptor);
wapi_ret_direct(IsValidSid);
wapi_ret_direct(IsWellKnownSid);
wapi_ret_true(MakeAbsoluteSD);
wapi_ret_true(MakeSelfRelativeSD);
wapi_ret_true_WAO(ObjectCloseAuditAlarm); // ObjectCloseAuditAlarmA from WinBase.h
wapi_ret_true_WAO(ObjectDeleteAuditAlarm); // ObjectDeleteAuditAlarmA from WinBase.h
wapi_ret_true_WAO(ObjectOpenAuditAlarm); // ObjectOpenAuditAlarmA from WinBase.h
wapi_ret_true_WAO(ObjectPrivilegeAuditAlarm); // ObjectPrivilegeAuditAlarmA from WinBase.h
wapi_ret_true(PrivilegeCheck);
wapi_ret_true_WAO(PrivilegedServiceAuditAlarm); // PrivilegedServiceAuditAlarmA from WinBase.h
wapi_ret_true(RevertToSelf);
wapi_ret_true(SetAclInformation);
wapi_ret_true_WAO(SetFileSecurity); // SetFileSecurityA from WinBase.h
wapi_ret_true(SetKernelObjectSecurity);
wapi_ret_true(SetPrivateObjectSecurity);
wapi_ret_true(SetPrivateObjectSecurityEx);
wapi_ret_true(SetSecurityDescriptorControl);
wapi_ret_true(SetSecurityDescriptorDacl);
wapi_ret_true(SetSecurityDescriptorGroup);
wapi_ret_true(SetSecurityDescriptorOwner);
wapi_ret_true(SetSecurityDescriptorSacl);
wapi_ret_true(SetTokenInformation);
wapi_ret_true(SetCachedSigningLevel);
wapi_ret_true(GetCachedSigningLevel);
wapi_ret_true(DeriveCapabilitySidsFromName);
wapi_ret_direct(GetLengthSid);
wapi_ret_direct(GetSecurityDescriptorLength);
wapi_ret_true(GetSecurityDescriptorRMControl);
wapi_ret_direct(GetSidLengthRequired);
wapi_ret_true(SetSecurityDescriptorRMControl);
wapi_ret_true(CveEventWrite);
// GetSidSubAuthority
inline PDWORD GetSidSubAuthority(PSID pSid, DWORD nSubAuthority)
ret_safe_to(auto h = ::GetSidSubAuthority(pSid, nSubAuthority), h);
// GetSidIdentifierAuthority
inline PSID_IDENTIFIER_AUTHORITY GetSidIdentifierAuthority(PSID pSid)
ret_safe_to(auto h = ::GetSidIdentifierAuthority(pSid), h);
// GetSidSubAuthorityCount
inline PUCHAR GetSidSubAuthorityCount(PSID pSid)
ret_safe_to(auto h = ::GetSidSubAuthorityCount(pSid), h);
wapi_ret_true(FreeSid);
wapi_ret_direct(MapGenericMask);
wapi_ret_direct(QuerySecurityAccessMask);
wapi_ret_direct(SetSecurityAccessMask);
#pragma endregion

#pragma region AclApi.h
wapi_ret_true_WAO(SetEntriesInAcl);
wapi_ret_true_WAO(GetExplicitEntriesFromAcl);
wapi_ret_true_WAO(GetEffectiveRightsFromAcl);
wapi_ret_true_WAO(GetAuditedPermissionsFromAcl);
wapi_ret_true_WAO(GetNamedSecurityInfo);
wapi_ret_true(GetSecurityInfo);
wapi_ret_true_WAO(SetNamedSecurityInfo);
wapi_ret_true(SetSecurityInfo);
wapi_ret_true_WAO(GetInheritanceSource);
wapi_ret_true(FreeInheritedFromArray);
wapi_ret_true_WAO(TreeResetNamedSecurityInfo);
wapi_ret_true_WAO(TreeSetNamedSecurityInfo);
wapi_ret_true_WAO(BuildSecurityDescriptor);
wapi_ret_true_WAO(LookupSecurityDescriptorParts);
wapi_ret_direct_WAO(BuildExplicitAccessWithName);
wapi_ret_direct_WAO(BuildTrusteeWithName);
wapi_ret_direct_WAO(BuildTrusteeWithSid);
wapi_ret_direct_WAO(BuildTrusteeWithObjectsAndSid);
wapi_ret_direct_WAO(BuildTrusteeWithObjectsAndName);
//wapi_ret_direct_WAO(GetTrusteeName);
wapi_ret_direct_WAO(GetTrusteeType);
wapi_ret_direct_WAO(GetTrusteeForm);
#pragma endregion

}


}
