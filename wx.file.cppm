module;

#define WX_CPPM_FILE
#include "wx_file"

export module wx.file;

import wx.win32;
import wx.resource;

#pragma region Win32 Prototype Includes
namespace WX {
	
#pragma region FileApi.h
#undef FindFirstChangeNotification
inline HANDLE FindFirstChangeNotification(LPCSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter)
	safe_ret_as(auto h = ::FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter); h != INVALID_HANDLE_VALUE, h);
inline HANDLE FindFirstChangeNotification(LPCWSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter)
	safe_ret_as(auto h = ::FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter); h != INVALID_HANDLE_VALUE, h);
#undef FindNextFile
inline void FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
	safe_ret_as(::FindNextFileA(hFindFile, lpFindFileData));
inline void FindNextFile(HANDLE hFindFile, LPWIN32_FIND_DATAW lpFindFileData)
	safe_ret_as(::FindNextFileW(hFindFile, lpFindFileData));
#undef GetDiskFreeSpace
inline void GetDiskFreeSpace(LPCSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector,
							  LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
	safe_ret_as(::GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector,
										   lpNumberOfFreeClusters, lpTotalNumberOfClusters));
inline void GetDiskFreeSpace(LPCWSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector,
							 LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
	safe_ret_as(::GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector,
										   lpNumberOfFreeClusters, lpTotalNumberOfClusters));
#undef GetDiskFreeSpaceEx
inline void GetDiskFreeSpace(LPCSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailable,
							   PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes)
	safe_ret_as(::GetDiskFreeSpaceExA(lpDirectoryName, lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes));
inline void GetDiskFreeSpace(LPCWSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailable,
							   PULARGE_INTEGER lpTotalNumberOfBytes, PULARGE_INTEGER lpTotalNumberOfFreeBytes)
	safe_ret_as(::GetDiskFreeSpaceExW(lpDirectoryName, lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes));
#undef GetDiskSpaceInformation
inline void GetDiskSpaceInformation(LPCSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo)
	safe_ret_as(SUCCEEDED(::GetDiskSpaceInformationA(rootPath, diskSpaceInfo)));
inline void GetDiskSpaceInformation(LPCWSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo)
	safe_ret_as(SUCCEEDED(::GetDiskSpaceInformationW(rootPath, diskSpaceInfo)));
#undef GetDriveType
inline UINT GetDriveType(LPCSTR lpRootPathName)
	ret_as(::GetDriveTypeA(lpRootPathName));
inline UINT GetDriveType(LPCWSTR lpRootPathName)
	ret_as(::GetDriveTypeW(lpRootPathName));
#undef GetFinalPathNameByHandle
inline DWORD GetFinalPathNameByHandle(HANDLE hFile, LPSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags)
	safe_ret_as(auto n = ::GetFinalPathNameByHandleA(hFile, lpszFilePath, cchFilePath, dwFlags), n);
inline DWORD GetFinalPathNameByHandle(HANDLE hFile, LPWSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags)
	safe_ret_as(auto n = ::GetFinalPathNameByHandleW(hFile, lpszFilePath, cchFilePath, dwFlags), n);
#undef GetLongPathName
inline DWORD GetLongPathName(LPCSTR lpszShortPath, LPSTR lpszLongPath, DWORD cchBuffer)
	safe_ret_as(auto n = ::GetLongPathNameA(lpszShortPath, lpszLongPath, cchBuffer), n);
inline DWORD GetLongPathName(LPCWSTR lpszShortPath, LPWSTR lpszLongPath, DWORD cchBuffer)
	safe_ret_as(auto n = ::GetLongPathNameW(lpszShortPath, lpszLongPath, cchBuffer), n);
#undef GetShortPathName
// from WinBase.h
inline DWORD GetShortPathName(LPCSTR lpszLongPath, LPSTR lpszShortPath, DWORD cchBuffer)
	safe_ret_as(auto res = ::GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer), res);
inline DWORD GetShortPathName(LPCWSTR lpszLongPath, LPWSTR lpszShortPath, DWORD cchBuffer)
	safe_ret_as(auto res = ::GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer), res);
#undef GetTempFileName
inline UINT GetTempFileName(LPCSTR lpPathName, LPCSTR lpPrefixString, UINT uUnique, LPSTR lpTempFileName)
	safe_ret_as(auto n = ::GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName), n);
inline UINT GetTempFileName(LPCWSTR lpPathName, LPCWSTR lpPrefixString, UINT uUnique, LPWSTR lpTempFileName)
	safe_ret_as(auto n = ::GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName), n);
// GetVolumeInformationByHandle
inline void GetVolumeInformationByHandle(HANDLE hFile, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize,
										 LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
										 LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize)
	safe_ret_as(::GetVolumeInformationByHandleW(hFile, lpVolumeNameBuffer, nVolumeNameSize,
													   lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags,
													   lpFileSystemNameBuffer, nFileSystemNameSize));
#undef GetVolumeInformation
inline void GetVolumeInformation(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize,
									LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
									LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize)
	safe_ret_as(::GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize,
											   lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags,
											   lpFileSystemNameBuffer, nFileSystemNameSize));
inline void GetVolumeInformation(LPCWSTR lpRootPathName, LPWSTR lpVolumeNameBuffer, DWORD nVolumeNameSize,
								 LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
								 LPDWORD lpFileSystemFlags, LPWSTR lpFileSystemNameBuffer, DWORD nFileSystemNameSize)
	safe_ret_as(::GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize,
											   lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags,
											   lpFileSystemNameBuffer, nFileSystemNameSize));
// FindFirstStream
inline HANDLE FindFirstStream(LPCWSTR lpFileName, STREAM_INFO_LEVELS InfoLevel, LPVOID lpFindStreamData, DWORD dwFlags)
	safe_ret_as(auto h = ::FindFirstStreamW(lpFileName, InfoLevel, lpFindStreamData, dwFlags), h);
// FindNextStream
inline void FindNextStream(HANDLE hFindStream, LPVOID lpFindStreamData)
	safe_ret_as(::FindNextStreamW(hFindStream, lpFindStreamData));
#undef GetTempPath
inline DWORD GetTempPath(LPSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto n = ::GetTempPathA(nSize, lpBuffer), n);
inline DWORD GetTempPath(LPWSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto n = ::GetTempPathW(nSize, lpBuffer), n);
#undef FindFirstFileName
inline HANDLE FindFirstFileName(LPCWSTR lpFileName, DWORD dwFlags, LPDWORD StringLength, LPWSTR LinkName)
	safe_ret_as(auto h = ::FindFirstFileNameW(lpFileName, dwFlags, StringLength, LinkName); h != INVALID_HANDLE_VALUE, h);
// FindNextFileName
inline void FindNextFileName(HANDLE hFindStream, LPDWORD StringLength, LPWSTR LinkName)
	safe_ret_as(::FindNextFileNameW(hFindStream, StringLength, LinkName));
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
#	undef GetTempPath2
inline DWORD GetTempPath2(LPSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto n = ::GetTempPath2A(nSize, lpBuffer), n);
inline DWORD GetTempPath2(LPWSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto n = ::GetTempPath2W(nSize, lpBuffer), n);
#endif
#undef CreateFile
inline HANDLE CreateFile(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
						 DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
	safe_ret_as(auto h = ::CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
											  dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile); h != INVALID_HANDLE_VALUE, h);
inline HANDLE CreateFile(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
						 DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
	safe_ret_as(auto h = ::CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
											  dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile); h != INVALID_HANDLE_VALUE, h);
#undef CreateDirectory
inline void CreateDirectory(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(::CreateDirectoryA(lpPathName, lpSecurityAttributes));
inline void CreateDirectory(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(::CreateDirectoryW(lpPathName, lpSecurityAttributes));
#if defined(NTDDI_WIN11_GE) && (NTDDI_VERSION >= NTDDI_WIN11_GE) && !__GNUC__
#undef CreateDirectory2
inline void CreateDirectory(LPCSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode,
							DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(::CreateDirectory2A(lpPathName, dwDesiredAccess, dwShareMode, DirectoryFlags, lpSecurityAttributes));
inline void CreateDirectory(LPCWSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode,
							DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(::CreateDirectory2W(lpPathName, dwDesiredAccess, dwShareMode, DirectoryFlags, lpSecurityAttributes));
#undef RemoveDirectory2
inline void RemoveDirectory(LPCSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags)
	safe_ret_as(::RemoveDirectory2A(lpPathName, DirectoryFlags));
inline void RemoveDirectory(LPCWSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags)
	safe_ret_as(::RemoveDirectory2W(lpPathName, DirectoryFlags));
#undef DeleteFile
// from WinBase.h
inline void DeleteFile(LPCSTR lpFileName)
	safe_ret_as(::DeleteFileA(lpFileName));
inline void DeleteFile(LPCWSTR lpFileName)
	safe_ret_as(::DeleteFileW(lpFileName));
#undef DeleteFile2
inline void DeleteFile(LPCSTR lpFileName, DWORD Flags)
	safe_ret_as(::DeleteFile2A(lpFileName, Flags));
inline void DeleteFile(LPCWSTR lpFileName, DWORD Flags)
	safe_ret_as(::DeleteFile2W(lpFileName, Flags));
#endif
#pragma endregion

#pragma region WinBase.h (part)
#pragma endregion

}
#pragma endregion

export namespace WX {

#pragma region File
enum_flags(FileAccess, HandleAccess,
	Default = 0,
	ReadData             = FILE_READ_DATA,        // file & pipe
	ListDirectory        = FILE_LIST_DIRECTORY,   // directory
	WriteData            = FILE_WRITE_DATA,       // file & pipe
	AddFile              = FILE_ADD_FILE,         // directory
	AppendData           = FILE_APPEND_DATA,      // file
	AddSubdirectory      = FILE_ADD_SUBDIRECTORY, // directory
	CreatePipeInstance   = FILE_CREATE_PIPE_INSTANCE, // named pipe
	ReadEA               = FILE_READ_EA,  // file & directory
	WriteEA              = FILE_WRITE_EA, // file & directory
	Execute              = FILE_EXECUTE,  // file
	Traverse             = FILE_TRAVERSE, // directory
	DeleteChild          = FILE_DELETE_CHILD,     // directory
	ReadAttributes       = FILE_READ_ATTRIBUTES,  // all
	WriteAttributes      = FILE_WRITE_ATTRIBUTES, // all
	GenericRead    = FILE_GENERIC_READ,
	GenericWrite   = FILE_GENERIC_WRITE,
	GenericExecute = FILE_GENERIC_EXECUTE,
	All            = FILE_ALL_ACCESS);
enum_flags(FileAttribute, DWORD,
	No = 0,
	ReadOnly              = FILE_ATTRIBUTE_READONLY,
	Hidden                = FILE_ATTRIBUTE_HIDDEN,
	System                = FILE_ATTRIBUTE_SYSTEM,
	Directory             = FILE_ATTRIBUTE_DIRECTORY,
	Archive               = FILE_ATTRIBUTE_ARCHIVE,
	Device                = FILE_ATTRIBUTE_DEVICE,
	Normal                = FILE_ATTRIBUTE_NORMAL,
	Temporary             = FILE_ATTRIBUTE_TEMPORARY,
	SparseFile            = FILE_ATTRIBUTE_SPARSE_FILE,
	ReparsePoint          = FILE_ATTRIBUTE_REPARSE_POINT,
	Compressed            = FILE_ATTRIBUTE_COMPRESSED,
	Offline               = FILE_ATTRIBUTE_OFFLINE,
	NotContentIndexed     = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED,
	Encrypted             = FILE_ATTRIBUTE_ENCRYPTED,
	IntegrityStream       = FILE_ATTRIBUTE_INTEGRITY_STREAM,
	Virtual               = FILE_ATTRIBUTE_VIRTUAL,
	NoScrubData           = FILE_ATTRIBUTE_NO_SCRUB_DATA,
	EA                    = FILE_ATTRIBUTE_EA,
	Pinned                = FILE_ATTRIBUTE_PINNED,
	Unpinned              = FILE_ATTRIBUTE_UNPINNED,
	RecallOnOpen          = FILE_ATTRIBUTE_RECALL_ON_OPEN,
	RecallOnDataAccess    = FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS);
enum_flags(FileFlag, DWORD,
	WriteThrough          = FILE_FLAG_WRITE_THROUGH,
	Overlapped            = FILE_FLAG_OVERLAPPED,
	NoBuffering           = FILE_FLAG_NO_BUFFERING,
	RandomAccess          = FILE_FLAG_RANDOM_ACCESS,
	SequentialScan        = FILE_FLAG_SEQUENTIAL_SCAN,
	DeleteOnClose         = FILE_FLAG_DELETE_ON_CLOSE,
	BackupSemantics       = FILE_FLAG_BACKUP_SEMANTICS,
	PosixSemantics        = FILE_FLAG_POSIX_SEMANTICS,
	SessionAware          = FILE_FLAG_SESSION_AWARE,
	OpenReparsePoint      = FILE_FLAG_OPEN_REPARSE_POINT,
	OpenNoRecall          = FILE_FLAG_OPEN_NO_RECALL,
	FirstPipeInstance     = FILE_FLAG_FIRST_PIPE_INSTANCE,
	OpenRequiringOplock   = FILE_FLAG_OPEN_REQUIRING_OPLOCK);//,
//	IgnoreImpersonatedDevicemap  = FILE_FLAG_IGNORE_IMPERSONATED_DEVICEMAP);
enum_flags(FileShares, DWORD,
	No = 0,
	Read   = FILE_SHARE_READ,
	Write  = FILE_SHARE_WRITE,
	Delete = FILE_SHARE_DELETE);
enum_class(FileTypes, DWORD, 
	Unknown = FILE_TYPE_UNKNOWN,
	Disk      = FILE_TYPE_DISK,
	Char      = FILE_TYPE_CHAR,
	Pipe      = FILE_TYPE_PIPE,
	Remote    = FILE_TYPE_REMOTE);
enum_flags(PageProtect, DWORD,
	NoAccess           = PAGE_NOACCESS,
	ReadOnly           = PAGE_READONLY,
	ReadWrite          = PAGE_READWRITE,
	WriteCopy          = PAGE_WRITECOPY,
	Execute            = PAGE_EXECUTE,
	ExecuteRead        = PAGE_EXECUTE_READ,
	ExecuteReadWrite   = PAGE_EXECUTE_READWRITE,
	ExecuteWriteCopy   = PAGE_EXECUTE_WRITECOPY);
enum_flags(MapAccess, DWORD,
	Write      = FILE_MAP_WRITE,
	Read       = FILE_MAP_READ,
	All        = FILE_MAP_ALL_ACCESS,
	Execute    = FILE_MAP_EXECUTE,
	Copy       = FILE_MAP_COPY,
	Targets    = FILE_MAP_TARGETS_INVALID,
	LargePages = FILE_MAP_LARGE_PAGES,
	ReadWrite = FILE_MAP_WRITE | FILE_MAP_READ);
//enum_flags(FileDispose)
struct FileTimes { FileTime Creation, LastAccess, LastWrite; };
class FileBaseInfo : public StructShim<FILE_BASIC_INFO> {
public:
	using Super = StructShim<FILE_BASIC_INFO>;
public:
	FileBaseInfo() {}
	FileBaseInfo(const FILE_BASIC_INFO &fbi) : Super(fbi) {}
public: // Property - TimeCreation
	/* W */ inline auto &TimeCreation(FileTime CreationTime) ret_to_self(this->CreationTime = CreationTime);
	/* R */ inline FileTime TimeCreation() const ret_as(this->CreationTime);
public: // Property - TimeLastAccess
	/* W */ inline auto &TimeLastAccess(FileTime LastAccessTime) ret_to_self(this->LastAccessTime = LastAccessTime);
	/* R */ inline FileTime TimeLastAccess() const ret_as(this->LastAccessTime);
public: // Property - TimeLastWrite
	/* W */ inline auto &TimeLastWrite(FileTime LastWriteTime) ret_to_self(this->LastWriteTime = LastWriteTime);
	/* R */ inline FileTime TimeLastWrite() const ret_as(this->LastWriteTime);
public: // Property - TimeChange
	/* W */ inline auto &TimeChange(FileTime ChangeTime) ret_to_self(this->ChangeTime = ChangeTime);
	/* R */ inline FileTime TimeChange() const ret_as(this->ChangeTime);
public: // Property - Attributes
	/* W */ inline auto &Attributes(FileAttribute fa) ret_to_self(this->FileAttributes = fa.yield());
	/* R */ inline FileAttribute Attributes() const ret_as(reuse_cast<FileAttribute>(this->FileAttributes));
};
class BaseOf_Handle(File) {
public:
	using Super = HandleBase<File>;
protected:
	File(HANDLE h) : Super(h) {}
	File(const File &f) : Super(f) {}
public:
	File() {}
	File(Nu) {}
	File(File &f) : Super(f) {}
	File(File &&f) : Super(f) {}
public:
	template<bool IsUnicode = WX::IsUnicode>
	class CreateStruct {
		using LPCTSTR = LPCXSTR<IsUnicode>;
		LPCTSTR lpFileName;
		FileAccess dwDesiredAccess = FileAccess::Default;
		FileShares dwShareMode = FileShares::No;
		LPSECURITY_ATTRIBUTES lpAttributes = O;
		DWORD dwCreationDisposition = 0;
		FileAttribute dwFlagsAndAttributes = FileAttribute::No;
		HANDLE hTemplateFile = O;
	public:
		CreateStruct(LPCTSTR lpFileName) : lpFileName(lpFileName) {}
	public:
		inline auto &Accesses(FileAccess dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Share(FileShares dwShareMode) ret_to_self(this->dwShareMode = dwShareMode);
		inline auto &Security(LPSECURITY_ATTRIBUTES lpAttributes) ret_to_self(this->lpAttributes = lpAttributes);
		inline auto &Template(HANDLE hTemplateFile) ret_to_self(this->hTemplateFile = hTemplateFile);
		inline auto &Attributes(FileAttribute dwAttributes) ret_to_self(this->dwFlagsAndAttributes = dwAttributes);
		inline auto &Flags(FileFlag dwFlags) ret_to_self(this->dwFlagsAndAttributes = dwFlags.yield());
	public:
		inline auto &CreateNew() ret_to_self(this->dwCreationDisposition = CREATE_NEW);
		inline auto &CreateAlways() ret_to_self(this->dwCreationDisposition = CREATE_ALWAYS);
		inline auto &OpenExisting() ret_to_self(this->dwCreationDisposition = OPEN_EXISTING);
		inline auto &OpenAlways() ret_to_self(this->dwCreationDisposition = OPEN_ALWAYS);
		inline auto &TruncateExisting() ret_to_self(this->dwCreationDisposition = TRUNCATE_EXISTING);
	public:
		inline operator File() ret_as(WX::CreateFile(lpFileName, dwDesiredAccess.yield(), dwShareMode.yield(), lpAttributes, dwCreationDisposition, dwFlagsAndAttributes.yield(), hTemplateFile));
	};
	static inline CreateStruct<false> Create(LPCSTR lpFileName) ret_as(lpFileName);
	static inline CreateStruct<true> Create(LPCWSTR lpFileName) ret_as(lpFileName);
	template<bool IsUnicode = WX::IsUnicode>
	class MappingCreateStruct {
		using LPCTSTR = LPCXSTR<IsUnicode>;
		HANDLE hFile;
		LPSECURITY_ATTRIBUTES lpAttributes = O;
		DWORD flProtect = PageProtect::ReadWrite.yield();
		DWORD dwMaximumSizeHigh = 0;
		DWORD dwMaximumSizeLow = 0;
		LPCTSTR lpName;
	public:
		MappingCreateStruct(HANDLE hFile, LPCTSTR lpName, Int64U size) :
			hFile(hFile),
			dwMaximumSizeHigh((DWORD)(size >> 32)), dwMaximumSizeLow((DWORD)size),
			lpName(lpName) {}
	public:
		inline auto &Security(LPSECURITY_ATTRIBUTES lpAttributes) ret_to_self(this->lpAttributes = lpAttributes);
		inline auto &Protect(PageProtect pa) ret_to_self(this->flProtect = pa.yield());
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator File() safe_ret_as(auto h = WX::CreateFileMapping(hFile, lpAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName), h);
	};
	inline MappingCreateStruct<> CreateMapping(Int64U size) ret_as({ self, O, size });
	inline MappingCreateStruct<false> CreateMapping(LPCSTR lpName, Int64U size) ret_as({ self, lpName, size });
	inline MappingCreateStruct<true> CreateMapping(LPCWSTR lpName, Int64U size) ret_as({ self, lpName, size });
	template<bool IsUnicode = WX::IsUnicode>
	class MappingOpenStruct {
		using LPCTSTR = LPCXSTR<IsUnicode>;
		DWORD dwDesiredAccess = MapAccess::ReadWrite.yield();
		bool bInheritHandle = false;
		LPCTSTR lpName;
	public:
		MappingOpenStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Accesses(MapAccess pa) ret_to_self(this->dwDesiredAccess = pa.yield());
		inline auto &Inherit(bool bInheritHandle) ret_to_self(this->bInheritHandle = bInheritHandle);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator File() safe_ret_as(auto h = WX::OpenFileMapping(dwDesiredAccess, bInheritHandle, lpName), h);
	};
	static inline MappingOpenStruct<false> OpenMapping(LPCSTR lpName) ret_as(lpName);
	static inline MappingOpenStruct<true> OpenMapping(LPCWSTR lpName) ret_as(lpName);
public:
	static inline void Delete(LPCSTR lpFileName) ret_as(WX::DeleteFile(lpFileName));
	static inline void Delete(LPCWSTR lpFileName) ret_as(WX::DeleteFile(lpFileName));
	static inline void Copy(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, bool bFailIfExists = false) ret_to(WX::CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists));
	static inline void Copy(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName, bool bFailIfExists = false) ret_to(WX::CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists));
	static inline void Move(LPCSTR lpExistingFileName, LPCSTR lpNewFileName) ret_to(WX::MoveFile(lpExistingFileName, lpNewFileName));
	static inline void Move(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName) ret_to(WX::MoveFile(lpExistingFileName, lpNewFileName));
public:
	class MapPointer {
		friend class File;
		mutable void *ptr = O;
	protected:
		MapPointer(void *ptr) : ptr(ptr) {}
		MapPointer(const MapPointer &m) : ptr(m.ptr) ret_to(m.ptr = O);
	public:
		MapPointer() {}
		MapPointer(Nu) {}
		MapPointer(MapPointer &p) : ptr(p.ptr) ret_to(p.ptr = O);
		MapPointer(MapPointer &&p) : ptr(p.ptr) ret_to(p.ptr = O);
		~MapPointer() {
			if (ptr)
				UnmapViewOfFile(ptr);
			ptr = O;
		}
		template<class AnyType>
		inline operator AnyType *() ret_as((AnyType *)ptr);
		inline void *operator&() ret_as(ptr);
		inline auto &operator=(MapPointer &m) ret_to_self(std::swap(m.ptr, ptr));
		inline auto &operator=(MapPointer &&m) ret_to_self(std::swap(m.ptr, ptr));
		inline auto &operator=(const MapPointer &m) const ret_to_self(std::swap(m.ptr, ptr));
	};
	inline MapPointer MapView(MapAccess acs = MapAccess::All, Int64U offset = 0, SizeT size = 0) safe_ret_as(auto p = MapViewOfFile(self, acs.yield(), (DWORD)(offset >> 32), (DWORD)offset, size), p);

	inline DWORD Read(LPVOID lpBuffer, DWORD dwNumberOfBytesToRead) safe_ret_as(ReadFile(self, lpBuffer, dwNumberOfBytesToRead, &dwNumberOfBytesToRead, O), dwNumberOfBytesToRead);
	inline DWORD Write(LPCVOID lpBuffer, DWORD dwNumberOfBytesToRead) safe_ret_as(WriteFile(self, lpBuffer, dwNumberOfBytesToRead, &dwNumberOfBytesToRead, O), dwNumberOfBytesToRead);

	inline void Flush() safe_ret_as(FlushFileBuffers(self));

#pragma region Properties
public: // Property - Size
	/* W */ inline Int64U Size() const safe_ret_to(Int64U size = 0, GetFileSizeEx(self, (PLARGE_INTEGER)&size), size);
public: // Property - Time
	/* W */ inline FileTimes Times() const safe_ret_to(FileTimes ts, GetFileTime(self, &ts.Creation, &ts.LastAccess, &ts.LastWrite), ts);
public: // Property - Type
	/* W */ inline FileTypes Type() const ret_safe_to(auto type = GetFileType(self), reuse_cast<FileTypes>(type));
#pragma endregion

};
using CFile = ProxyView<File>;
#pragma endregion

#pragma region Comm
enum_class(Parities, BYTE,
	No        = NOPARITY,
	Odd       = ODDPARITY,
	Even      = EVENPARITY,
	Mark      = MARKPARITY,
	Space     = SPACEPARITY);
enum_class(StopBits, BYTE,
	One  = ONESTOPBIT,
	One5 = ONE5STOPBITS,
	Two  = TWOSTOPBITS);
enum_class(DtrCtrl, DWORD,
	Disable   = DTR_CONTROL_DISABLE,
	Enable    = DTR_CONTROL_ENABLE,
	HandShake = DTR_CONTROL_HANDSHAKE);
enum_class(RtsCtrl, DWORD,
	Disable   = RTS_CONTROL_DISABLE,
	Enable    = RTS_CONTROL_ENABLE,
	HandShake = RTS_CONTROL_HANDSHAKE,
	Toggle    = RTS_CONTROL_TOGGLE);
enum_flags(CommPurge, DWORD,
	TxAbort   = PURGE_TXABORT,
	RxAbort   = PURGE_RXABORT,
	TxClear   = PURGE_TXCLEAR,
	RxClear   = PURGE_RXCLEAR,
	All       = PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
enum_flags(ModemStatus, DWORD,
	CTS       = MS_CTS_ON,
	DSR       = MS_DSR_ON,
	Ring      = MS_RING_ON,
	RLSD      = MS_RLSD_ON);
enum_flags(CommEvent, DWORD,
	RxChar    = EV_RXCHAR,
	RxFlag    = EV_RXFLAG,
	TxEmpty   = EV_TXEMPTY,
	Cts       = EV_CTS,
	Dsr       = EV_DSR,
	Rlsd      = EV_RLSD,
	Break     = EV_BREAK,
	Err       = EV_ERR,
	Ring      = EV_RING,
	PErr      = EV_PERR,
	Rx80Full  = EV_RX80FULL,
	Event1    = EV_EVENT1,
	Event2    = EV_EVENT2);
enum_class(CommSubTypes, DWORD,
	Unspecified      = PST_UNSPECIFIED,
	RS232            = PST_RS232,
	ParallelPort     = PST_PARALLELPORT,
	RS422            = PST_RS422,
	RS423            = PST_RS423,
	RS449            = PST_RS449,
	Modem            = PST_MODEM,
	Fax              = PST_FAX,
	Scanner          = PST_SCANNER,
	NetworkBridge    = PST_NETWORK_BRIDGE,
	Lat              = PST_LAT,
	TcpIpTelnet      = PST_TCPIP_TELNET,
	X25              = PST_X25);
enum_flags(CommCapability, DWORD,
	DTRDSR        = PCF_DTRDSR,
	RTSCTS        = PCF_RTSCTS,
	RLSD          = PCF_RLSD,
	ParityCheck   = PCF_PARITY_CHECK,
	XONXOFF       = PCF_XONXOFF,
	SetXChar      = PCF_SETXCHAR,
	Totaltimeouts = PCF_TOTALTIMEOUTS,
	IntTimeouts   = PCF_INTTIMEOUTS,
	SpecialChars  = PCF_SPECIALCHARS,
	_16BitMode    = PCF_16BITMODE);
enum_flags(CommBaud, DWORD,
	_075             = BAUD_075,
	_110             = BAUD_110,
	_134_5           = BAUD_134_5,
	_150             = BAUD_150,
	_300             = BAUD_300,
	_600             = BAUD_600,
	_1200            = BAUD_1200,
	_1800            = BAUD_1800,
	_2400            = BAUD_2400,
	_4800            = BAUD_4800,
	_7200            = BAUD_7200,
	_9600            = BAUD_9600,
	_14400           = BAUD_14400,
	_19200           = BAUD_19200,
	_38400           = BAUD_38400,
	_56K             = BAUD_56K,
	_128K            = BAUD_128K,
	_115200          = BAUD_115200,
	_57600           = BAUD_57600,
	_User            = BAUD_USER);
enum_flags(CommDataBit, WORD,
	_5               = DATABITS_5,
	_6               = DATABITS_6,
	_7               = DATABITS_7,
	_8               = DATABITS_8,
	_16              = DATABITS_16,
	_16X             = DATABITS_16X);
enum_flags(CommStopParity, WORD,
	_1               = STOPBITS_10,
	_15              = STOPBITS_15,
	_2               = STOPBITS_20,
	None             = PARITY_NONE,
	Odd              = PARITY_ODD,
	Even             = PARITY_EVEN,
	Mark             = PARITY_MARK,
	Space            = PARITY_SPACE);
enum_flags(CommParam, DWORD,
	Parity          = SP_PARITY,
	Baud            = SP_BAUD,
	DataBits        = SP_DATABITS,
	StopBits        = SP_STOPBITS,
	Handshaking     = SP_HANDSHAKING,
	ParityCheck     = SP_PARITY_CHECK,
	RLSD            = SP_RLSD);
struct CommStates : public StructShim<DCB> {
	using Super = StructShim<DCB>;
public:
	CommStates() ret_to(self->DCBlength = sizeof(DCB); self->fBinary = 1);
	CommStates(const DCB &dcb) : Super(dcb) {}
	CommStates(LPCSTR lpDef) : CommStates() safe_ret_as(BuildCommDCBA(lpDef, this));
	CommStates(LPCWSTR lpDef) : CommStates() safe_ret_as(BuildCommDCBW(lpDef, this));
	proxy_prop(BaudRate, BaudRate, DWORD, auto);
	proxy_prop(ByteSize, ByteSize, BYTE, auto);
public: // Property - Parity
	/* W */ inline auto&Parity(Parities parity) ret_to_self(self->Parity = parity.yield(), self->fParity = 1);
	proxy_prop_get(Parity,Parity,Parities);
public: // Property - StopBit
	/* W */ inline auto&StopBit(WX::StopBits stopbits) ret_to_self(self->StopBits = stopbits.yield());
	/* R */ inline auto StopBit() const ret_as(reuse_cast<WX::StopBits>(self->StopBits));
	proxy_prop_sync(OutxCtsFlow,fOutxCtsFlow,bool);
	proxy_prop_sync(OutxDsrFlow,fOutxDsrFlow,bool);
public: // Property - DtrControl
	proxy_prop_set(DtrControl,ctl,DtrCtrl);
	proxy_prop_get(DtrControl,fDtrControl,DtrCtrl);
public: // Property - RtsControl
	proxy_prop_set(RtsControl,ctl,RtsCtrl);
	proxy_prop_get(RtsControl,fRtsControl,RtsCtrl);
	proxy_prop_sync(DsrSensitivity,fDsrSensitivity,bool);
	proxy_prop_sync(TXContinueOnXoff,fTXContinueOnXoff,bool);
	proxy_prop_sync(OutX,fOutX,bool);
	proxy_prop_sync(InX,fInX,bool);
	proxy_prop_sync(Nu,fNull,bool);
	proxy_prop_sync(AbortOnError,fAbortOnError,bool);
	proxy_prop(XonLim, XonLim, WORD, auto);
	proxy_prop(XoffLim, XoffLim, WORD, auto);
	proxy_prop_sync(XonChar,XonChar,char);
	proxy_prop_sync(XoffChar,XoffChar,char);
	proxy_prop_sync(ErrorChar,ErrorChar,char);
	proxy_prop_sync(EofChar,EofChar,char);
	proxy_prop_sync(EvtChar,EvtChar,char);
};
struct CommProps : public StructShim<COMMPROP> {
	using Super = StructShim<COMMPROP>;
public:
	CommProps() ret_to(self->wPacketLength = sizeof(COMMPROP); self->dwProvSpec1 = COMMPROP_INITIALIZED);
	CommProps(const COMMPROP &cp) : Super(cp) {}
	proxy_prop_sync(PacketVersion,wPacketVersion,WORD);
public: // Property - ServiceMask
public: // Property - MaxTxQueue
proxy_prop_get(MaxTxQueue,dwMaxTxQueue,auto);
public: // Property - MaxRxQueue
proxy_prop_get(MaxRxQueue,dwMaxRxQueue,auto);
public: // Property - MaxBaud
	proxy_prop_get(MaxBaud,dwMaxBaud,CommBaud);
public: // Property - ProviderSubType
	proxy_prop_get(ProviderSubType,dwProvSubType,CommSubTypes);
public: // Property - ProviderCapabilities
	proxy_prop_get(ProviderCapabilities,dwProvCapabilities,CommCapability);
public: // Property - SettableParams
	proxy_prop_get(SettableParams,dwSettableParams,CommParam);
public: // Property - SettableBaud
	proxy_prop_get(SettableBaud,dwSettableBaud,CommBaud);
public: // Property - SettableData
	proxy_prop_get(SettableData,wSettableData,CommDataBit);
public: // Property - SettableStopParity
	proxy_prop_get(SettableStopParity,wSettableStopParity,CommStopParity);
public: // Property - CurrentTxQueue
proxy_prop_get(CurrentTxQueue,dwCurrentTxQueue,auto);
public: // Property - CurrentRxQueue
proxy_prop_get(CurrentRxQueue,dwCurrentRxQueue,auto);
	//DWORD dwProvSpec1;
	//DWORD dwProvSpec2;
	//WCHAR wcProvChar[1];
};
class CommConfig : public StructShim<COMMCONFIG> {
	HeapPointer<COMMCONFIG> lpCC;
public:
	CommConfig() {}
public: // Property - ProviderSubType
	/* W */ inline auto&ProviderSubType(CommSubTypes subType) ret_to_self(lpCC->dwProviderSubType = subType.yield());
	/* R */ inline auto ProviderSubType() const ret_as(reuse_cast<CommSubTypes>(lpCC->dwProviderSubType));
//public: // Property - ProviderName
//	/* W */ inline auto &ProviderName(LPCTSTR lpName) ret_to_self(lstrcpyn(self->szProvider, lpName, sizeof(self->szProvider) / sizeof(TCHAR)));
//	/* R */ inline String ProviderName() const ret_as(String(self->szProvider));
};
struct CommTimeouts : public StructShim<COMMTIMEOUTS> {
	using Super = StructShim<COMMTIMEOUTS>;
public:
	CommTimeouts() ret_to(self->ReadIntervalTimeout = MAXDWORD);
	CommTimeouts(const COMMTIMEOUTS &ct) : Super(ct) {}
	proxy_prop_sync(ReadInterval,ReadIntervalTimeout,DWORD);
	proxy_prop_sync(ReadTotalConst,ReadTotalTimeoutConstant,DWORD);
	proxy_prop_sync(ReadTotalMult,ReadTotalTimeoutMultiplier,DWORD);
	proxy_prop_sync(WriteTotalConst,WriteTotalTimeoutConstant,DWORD);
	proxy_prop_sync(WriteTotalMult,WriteTotalTimeoutMultiplier,DWORD);
};
class Comm : public File {
public:
	using Super = File;
protected:
	Comm(HANDLE hComm) : Super(hComm) {}
public:
	Comm() {}
public:
	inline void ClearBreak() ret_to(WX::ClearCommBreak(self));
//	inline void ClearErrors(CommClear cc = CommClear::All) ret_to(WX::ClearCommError(self, &cc.yield(), O));
	inline void Setup(DWORD dwInQueue, DWORD dwOutQueue) ret_to(WX::SetupComm(self, dwInQueue, dwOutQueue));
	inline void Purge(CommPurge cp = CommPurge::All) ret_to(WX::PurgeComm(self, cp.yield()));
	inline void Transmit(char ch)  ret_to(WX::TransmitCommChar(self, ch));
//	inline void WaitEvent(CommEvent ce = CommEvent::RxChar) ret_to(WX::WaitCommEvent(self, &ce.yield(), O));
	static inline Comm Open(ULONG uPortNumber, FileAccess desiredAccess, DWORD dwFlagsAndAttributes = 0)
		ret_as(WX::OpenCommPort(uPortNumber, desiredAccess.yield(), dwFlagsAndAttributes));
#pragma region Properties
public: // Property - Mask
	/* W */ inline auto&Mask(CommEvent ev) ret_to_self(WX::SetCommMask(self, ev.yield()));
	/* R */ inline auto Mask() const ret_to(DWORD dwMask; WX::GetCommMask(self, &dwMask), reuse_cast<CommEvent>(dwMask));
public: // Property - ModemStatus
	/* R */ inline auto ModemStatus() const ret_to(DWORD dwModemStatus; WX::GetCommModemStatus(self, &dwModemStatus), reuse_cast<WX::ModemStatus>(dwModemStatus));
public: // Property - States
	/* W */ inline auto&States(CommStates states) ret_to_self(WX::SetCommState(self, &states));
	/* R */ inline auto States() const ret_to(CommStates states; WX::GetCommState(self, &states), states);
public: // Property - Timeout
	/* W */ inline auto&Timeout(COMMTIMEOUTS ct) ret_to_self(WX::SetCommTimeouts(self, &ct));
	/* R */ inline auto Timeout() const ret_to(CommTimeouts ct; WX::GetCommTimeouts(self, &ct), ct);
public: // Property - Config
	///* W */ inline auto &Config(CommConfig cc) ret_to_self(WX::SetCommConfig(self, &cc, cc.dwSize));
	///* R */ inline auto Config() const ret_to(CommConfig cc; DWORD size = cc.dwSize; WX::GetCommConfig(self, &cc, &size), cc);
public: // Property - Props
	/* R */ inline auto Props() const ret_to(CommProps cp; WX::GetCommProperties(self, &cp), cp);
#pragma endregion
};
#pragma endregion

}
