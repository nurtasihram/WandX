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
// ConvertSidToStringSidA
inline void ConvertSidToStringSid(PSID Sid, LPSTR *StringSid)
safe_ret_as(::ConvertSidToStringSidA(Sid, StringSid));
// ConvertSidToStringSidW
inline void ConvertSidToStringSid(PSID Sid, LPWSTR *StringSid)
safe_ret_as(::ConvertSidToStringSidW(Sid, StringSid));
// ConvertStringSidToSidA
inline void ConvertStringSidToSid(LPCSTR StringSid, PSID *Sid)
safe_ret_as(::ConvertStringSidToSidA(StringSid, Sid));
// ConvertStringSidToSidW
inline void ConvertStringSidToSid(LPCWSTR StringSid, PSID *Sid)
safe_ret_as(::ConvertStringSidToSidW(StringSid, Sid));
// ConvertStringSecurityDescriptorToSecurityDescriptorA
inline void ConvertStringSecurityDescriptorToSecurityDescriptor(LPCSTR StringSecurityDescriptor,DWORD StringSDRevision,PSECURITY_DESCRIPTOR *SecurityDescriptor,PULONG SecurityDescriptorSize)
safe_ret_as(::ConvertStringSecurityDescriptorToSecurityDescriptorA(StringSecurityDescriptor,   StringSDRevision,   SecurityDescriptor,   SecurityDescriptorSize));
// ConvertStringSecurityDescriptorToSecurityDescriptorW
inline void ConvertStringSecurityDescriptorToSecurityDescriptor(LPCWSTR StringSecurityDescriptor,DWORD StringSDRevision,PSECURITY_DESCRIPTOR *SecurityDescriptor,PULONG SecurityDescriptorSize)
safe_ret_as(::ConvertStringSecurityDescriptorToSecurityDescriptorW(StringSecurityDescriptor,   StringSDRevision,   SecurityDescriptor,   SecurityDescriptorSize));
// ConvertSecurityDescriptorToStringSecurityDescriptorA
inline void ConvertSecurityDescriptorToStringSecurityDescriptor(PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD StringSDRevision,SECURITY_INFORMATION SecurityInformation,LPSTR *StringSecurityDescriptor,PULONG StringSecurityDescriptorLen)
safe_ret_as(::ConvertSecurityDescriptorToStringSecurityDescriptorA(SecurityDescriptor,   StringSDRevision,   SecurityInformation,   StringSecurityDescriptor,   StringSecurityDescriptorLen));
// ConvertSecurityDescriptorToStringSecurityDescriptorW
inline void ConvertSecurityDescriptorToStringSecurityDescriptor(PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD StringSDRevision,SECURITY_INFORMATION SecurityInformation,LPWSTR *StringSecurityDescriptor,PULONG StringSecurityDescriptorLen)
safe_ret_as(::ConvertSecurityDescriptorToStringSecurityDescriptorW(SecurityDescriptor,   StringSDRevision,   SecurityInformation,   StringSecurityDescriptor,   StringSecurityDescriptorLen));
#pragma endregion

#pragma region SecurityBaseAPI.h
wapi_ret_true(AccessCheck);
// AccessCheckAndAuditAlarmW
inline void AccessCheckAndAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPWSTR ObjectTypeName, LPWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose)
safe_ret_as(::AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose));
wapi_ret_true(AccessCheckByType);
wapi_ret_true(AccessCheckByTypeResultList);
// AccessCheckByTypeAndAuditAlarmW
inline void AccessCheckByTypeAndAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPCWSTR ObjectTypeName, LPCWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose)
safe_ret_as(::AccessCheckByTypeAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose));
// AccessCheckByTypeResultListAndAuditAlarmW
inline void AccessCheckByTypeResultListAndAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPCWSTR ObjectTypeName, LPCWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccessList, LPDWORD AccessStatusList, LPBOOL pfGenerateOnClose)
safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccessList, AccessStatusList, pfGenerateOnClose));
// AccessCheckByTypeResultListAndAuditAlarmByHandleW
inline void AccessCheckByTypeResultListAndAuditAlarmByHandle(LPCWSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, LPCWSTR ObjectTypeName, LPCWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccessList, LPDWORD AccessStatusList, LPBOOL pfGenerateOnClose)
safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmByHandleW(SubsystemName, HandleId, ClientToken, ObjectTypeName, ObjectName, SecurityDescriptor, PrincipalSelfSid, DesiredAccess, AuditType, Flags, ObjectTypeList, ObjectTypeListLength, GenericMapping, ObjectCreation, GrantedAccessList, AccessStatusList, pfGenerateOnClose));
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
// GetFileSecurityW
inline void GetFileSecurity(LPCWSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded)
safe_ret_as(::GetFileSecurityW(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded));
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
// ObjectCloseAuditAlarmW
inline void ObjectCloseAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
safe_ret_as(::ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose));
// ObjectDeleteAuditAlarmW
inline void ObjectDeleteAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
safe_ret_as(::ObjectDeleteAuditAlarmW(SubsystemName, HandleId, GenerateOnClose));
// ObjectOpenAuditAlarmW
inline void ObjectOpenAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPWSTR ObjectTypeName, LPWSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose)
safe_ret_as(::ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose));
// ObjectPrivilegeAuditAlarmW
inline void ObjectPrivilegeAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
safe_ret_as(::ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted));
wapi_ret_true(PrivilegeCheck);
// PrivilegedServiceAuditAlarmW
inline void PrivilegedServiceAuditAlarm(LPCWSTR SubsystemName, LPCWSTR ServiceName, HANDLE ClientToken, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
safe_ret_as(::PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted));
wapi_ret_true(RevertToSelf);
wapi_ret_true(SetAclInformation);
// SetFileSecurityW
inline void SetFileSecurity(LPCWSTR lpFileName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor)
safe_ret_as(::SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor));
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
// MapGenericMask
inline void MapGenericMask(PDWORD AccessMask, PGENERIC_MAPPING GenericMapping)
ret_to(::MapGenericMask(AccessMask, GenericMapping));
// QuerySecurityAccessMask
inline void QuerySecurityAccessMask(SECURITY_INFORMATION SecurityInformation, LPDWORD DesiredAccess)
ret_to(::QuerySecurityAccessMask(SecurityInformation, DesiredAccess));
// SetSecurityAccessMask
inline void SetSecurityAccessMask(SECURITY_INFORMATION SecurityInformation, LPDWORD DesiredAccess)
ret_to(::SetSecurityAccessMask(SecurityInformation, DesiredAccess));
#pragma endregion

#pragma region AclApi.h
// SetEntriesInAclA
inline void SetEntriesInAcl(ULONG cCountOfExplicitEntries, PEXPLICIT_ACCESS_A pListOfExplicitEntries, PACL OldAcl, PACL *NewAcl)
safe_ret_as(::SetEntriesInAclA(cCountOfExplicitEntries, pListOfExplicitEntries, OldAcl, NewAcl) == ERROR_SUCCESS);
// SetEntriesInAclW
inline void SetEntriesInAcl(ULONG cCountOfExplicitEntries, PEXPLICIT_ACCESS_W pListOfExplicitEntries, PACL OldAcl, PACL *NewAcl)
safe_ret_as(::SetEntriesInAclW(cCountOfExplicitEntries, pListOfExplicitEntries, OldAcl, NewAcl) == ERROR_SUCCESS);
// GetExplicitEntriesFromAclA
inline void GetExplicitEntriesFromAcl(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESS_A *pListOfExplicitEntries)
safe_ret_as(::GetExplicitEntriesFromAclA(pacl, pcCountOfExplicitEntries, pListOfExplicitEntries) == ERROR_SUCCESS);
// GetExplicitEntriesFromAclW
inline void GetExplicitEntriesFromAcl(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESS_W *pListOfExplicitEntries)
safe_ret_as(::GetExplicitEntriesFromAclW(pacl, pcCountOfExplicitEntries, pListOfExplicitEntries) == ERROR_SUCCESS);
// GetEffectiveRightsFromAclA
inline void GetEffectiveRightsFromAcl(PACL pacl, PTRUSTEE_A pTrustee, PACCESS_MASK pAccessRights)
safe_ret_as(::GetEffectiveRightsFromAclA(pacl, pTrustee, pAccessRights) == ERROR_SUCCESS);
// GetEffectiveRightsFromAclW
inline void GetEffectiveRightsFromAcl(PACL pacl, PTRUSTEE_W pTrustee, PACCESS_MASK pAccessRights)
safe_ret_as(::GetEffectiveRightsFromAclW(pacl, pTrustee, pAccessRights) == ERROR_SUCCESS);
// GetAuditedPermissionsFromAclA
inline void GetAuditedPermissionsFromAcl(PACL pacl, PTRUSTEE_A pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights)
safe_ret_as(::GetAuditedPermissionsFromAclA(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights) == ERROR_SUCCESS);
// GetAuditedPermissionsFromAclW
inline void GetAuditedPermissionsFromAcl(PACL pacl, PTRUSTEE_W pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights)
safe_ret_as(::GetAuditedPermissionsFromAclW(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights) == ERROR_SUCCESS);
// GetNamedSecurityInfoA
inline void GetNamedSecurityInfo(LPCSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID *ppsidOwner, PSID *ppsidGroup, PACL *ppDacl, PACL *ppSacl, PSECURITY_DESCRIPTOR *ppSecurityDescriptor)
safe_ret_as(::GetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor) == ERROR_SUCCESS);
// GetNamedSecurityInfoW
inline void GetNamedSecurityInfo(LPCWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID *ppsidOwner, PSID *ppsidGroup, PACL *ppDacl, PACL *ppSacl, PSECURITY_DESCRIPTOR *ppSecurityDescriptor)
safe_ret_as(::GetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor) == ERROR_SUCCESS);
wapi_ret_true(GetSecurityInfo);
// SetNamedSecurityInfoA
inline void SetNamedSecurityInfo(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl)
safe_ret_as(::SetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl) == ERROR_SUCCESS);
// SetNamedSecurityInfoW
inline void SetNamedSecurityInfo(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl)
safe_ret_as(::SetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl) == ERROR_SUCCESS);
wapi_ret_true(SetSecurityInfo);
// GetInheritanceSourceA
inline void GetInheritanceSource(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, BOOL Container, GUID **pObjectClassGuids, DWORD GuidCount, PACL pAcl, PFN_OBJECT_MGR_FUNCTS pfnArray, PGENERIC_MAPPING pGenericMapping, PINHERITED_FROMA pInheritArray)
safe_ret_as(::GetInheritanceSourceA(pObjectName, ObjectType, SecurityInfo, Container, pObjectClassGuids, GuidCount, pAcl, pfnArray, pGenericMapping, pInheritArray) == ERROR_SUCCESS);
// GetInheritanceSourceW
inline void GetInheritanceSource(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, BOOL Container, GUID **pObjectClassGuids, DWORD GuidCount, PACL pAcl, PFN_OBJECT_MGR_FUNCTS pfnArray, PGENERIC_MAPPING pGenericMapping, PINHERITED_FROMW pInheritArray)
safe_ret_as(::GetInheritanceSourceW(pObjectName, ObjectType, SecurityInfo, Container, pObjectClassGuids, GuidCount, pAcl, pfnArray, pGenericMapping, pInheritArray) == ERROR_SUCCESS);
wapi_ret_true(FreeInheritedFromArray);
// TreeResetNamedSecurityInfoA
inline void TreeResetNamedSecurityInfo(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args)
safe_ret_as(::TreeResetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, KeepExplicit, fnProgress, ProgressInvokeSetting, Args) == ERROR_SUCCESS);
// TreeResetNamedSecurityInfoW
inline void TreeResetNamedSecurityInfo(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args)
safe_ret_as(::TreeResetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, KeepExplicit, fnProgress, ProgressInvokeSetting, Args) == ERROR_SUCCESS);
// TreeSetNamedSecurityInfoA
inline void TreeSetNamedSecurityInfo(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, DWORD dwAction, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args)
safe_ret_as(::TreeSetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, dwAction, fnProgress, ProgressInvokeSetting, Args) == ERROR_SUCCESS);
// TreeSetNamedSecurityInfoW
inline void TreeSetNamedSecurityInfo(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, DWORD dwAction, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args)
safe_ret_as(::TreeSetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, dwAction, fnProgress, ProgressInvokeSetting, Args) == ERROR_SUCCESS);
// BuildSecurityDescriptorA
inline void BuildSecurityDescriptor(PTRUSTEE_A pOwner, PTRUSTEE_A pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESS_A pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESS_A pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG pSizeNewSD, PSECURITY_DESCRIPTOR *pNewSD)
safe_ret_as(::BuildSecurityDescriptorA(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListOfAuditEntries, pOldSD, pSizeNewSD, pNewSD) == ERROR_SUCCESS);
// BuildSecurityDescriptorW
inline void BuildSecurityDescriptor(PTRUSTEE_W pOwner, PTRUSTEE_W pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESS_W pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESS_W pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG pSizeNewSD, PSECURITY_DESCRIPTOR *pNewSD)
safe_ret_as(::BuildSecurityDescriptorW(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListOfAuditEntries, pOldSD, pSizeNewSD, pNewSD) == ERROR_SUCCESS);
// LookupSecurityDescriptorPartsA
inline void LookupSecurityDescriptorParts(PTRUSTEE_A *ppOwner, PTRUSTEE_A *ppGroup, PULONG pcCountOfAccessEntries, PEXPLICIT_ACCESS_A *ppListOfAccessEntries, PULONG pcCountOfAuditEntries, PEXPLICIT_ACCESS_A *ppListOfAuditEntries, PSECURITY_DESCRIPTOR pSD)
safe_ret_as(::LookupSecurityDescriptorPartsA(ppOwner, ppGroup, pcCountOfAccessEntries, ppListOfAccessEntries, pcCountOfAuditEntries, ppListOfAuditEntries, pSD) == ERROR_SUCCESS);
// LookupSecurityDescriptorPartsW
inline void LookupSecurityDescriptorParts(PTRUSTEE_W *ppOwner, PTRUSTEE_W *ppGroup, PULONG pcCountOfAccessEntries, PEXPLICIT_ACCESS_W *ppListOfAccessEntries, PULONG pcCountOfAuditEntries, PEXPLICIT_ACCESS_W *ppListOfAuditEntries, PSECURITY_DESCRIPTOR pSD)
safe_ret_as(::LookupSecurityDescriptorPartsW(ppOwner, ppGroup, pcCountOfAccessEntries, ppListOfAccessEntries, pcCountOfAuditEntries, ppListOfAuditEntries, pSD) == ERROR_SUCCESS);
// BuildExplicitAccessWithNameA
inline void BuildExplicitAccessWithName(PEXPLICIT_ACCESS_A pExplicitAccess, LPSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance)
ret_to(::BuildExplicitAccessWithNameA(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance));
// BuildExplicitAccessWithNameW
inline void BuildExplicitAccessWithName(PEXPLICIT_ACCESS_W pExplicitAccess, LPWSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance)
ret_to(::BuildExplicitAccessWithNameW(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance));
// BuildTrusteeWithNameA
inline void BuildTrusteeWithName(PTRUSTEE_A pTrustee, LPSTR pName)
ret_to(::BuildTrusteeWithNameA(pTrustee, pName));
// BuildTrusteeWithNameW
inline void BuildTrusteeWithName(PTRUSTEE_W pTrustee, LPWSTR pName)
ret_to(::BuildTrusteeWithNameW(pTrustee, pName));
// BuildTrusteeWithSidA
inline void BuildTrusteeWithSid(PTRUSTEE_A pTrustee, PSID pSid)
ret_to(::BuildTrusteeWithSidA(pTrustee, pSid));
// BuildTrusteeWithSidW
inline void BuildTrusteeWithSid(PTRUSTEE_W pTrustee, PSID pSid)
ret_to(::BuildTrusteeWithSidW(pTrustee, pSid));
// BuildTrusteeWithObjectsAndSidA
inline void BuildTrusteeWithObjectsAndSid(PTRUSTEE_A pTrustee, POBJECTS_AND_SID pObjSid, GUID *pObjectGuid, GUID *pInheritedObjectGuid, PSID pSid)
ret_to(::BuildTrusteeWithObjectsAndSidA(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid));
// BuildTrusteeWithObjectsAndSidW
inline void BuildTrusteeWithObjectsAndSid(PTRUSTEE_W pTrustee, POBJECTS_AND_SID pObjSid, GUID *pObjectGuid, GUID *pInheritedObjectGuid, PSID pSid)
ret_to(::BuildTrusteeWithObjectsAndSidW(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid));
// BuildTrusteeWithObjectsAndNameA
inline void BuildTrusteeWithObjectsAndName(PTRUSTEE_A pTrustee, POBJECTS_AND_NAME_A pObjName, SE_OBJECT_TYPE ObjectType, LPSTR ObjectTypeName, LPSTR InheritedObjectTypeName, LPSTR Name)
ret_to(::BuildTrusteeWithObjectsAndNameA(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name));
// BuildTrusteeWithObjectsAndNameW
inline void BuildTrusteeWithObjectsAndName(PTRUSTEE_W pTrustee, POBJECTS_AND_NAME_W pObjName, SE_OBJECT_TYPE ObjectType, LPWSTR ObjectTypeName, LPWSTR InheritedObjectTypeName, LPWSTR Name)
ret_to(::BuildTrusteeWithObjectsAndNameW(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name));
// GetTrusteeNameA
inline LPSTR GetTrusteeName(PTRUSTEE_A pTrustee)
ret_as(::GetTrusteeNameA(pTrustee));
// GetTrusteeNameW
inline LPWSTR GetTrusteeName(PTRUSTEE_W pTrustee)
ret_as(::GetTrusteeNameW(pTrustee));
// GetTrusteeTypeA
inline TRUSTEE_TYPE GetTrusteeType(PTRUSTEE_A pTrustee)
ret_as(::GetTrusteeTypeA(pTrustee));
// GetTrusteeTypeW
inline TRUSTEE_TYPE GetTrusteeType(PTRUSTEE_W pTrustee)
ret_as(::GetTrusteeTypeW(pTrustee));
// GetTrusteeFormA
inline TRUSTEE_FORM GetTrusteeForm(PTRUSTEE_A pTrustee)
ret_as(::GetTrusteeFormA(pTrustee));
// GetTrusteeFormW
inline TRUSTEE_FORM GetTrusteeForm(PTRUSTEE_W pTrustee)
ret_as(::GetTrusteeFormW(pTrustee));
#pragma endregion

}


}
