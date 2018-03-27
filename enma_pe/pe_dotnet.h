#pragma once

class dotnet_table {
    WORD                    major_version;
    WORD                    minor_version;
    DWORD                   flags;

    union {
        DWORD               entry_point_token;
        DWORD               entry_point_rva;
    };

    IMAGE_DATA_DIRECTORY    meta_data;
    IMAGE_DATA_DIRECTORY    resources;
    IMAGE_DATA_DIRECTORY    strong_name_signature;
    IMAGE_DATA_DIRECTORY    code_manager_table;
    IMAGE_DATA_DIRECTORY    vtable_fixups;
    IMAGE_DATA_DIRECTORY    export_address_table_jumps;
    IMAGE_DATA_DIRECTORY    managed_native_header;

public:
    dotnet_table::dotnet_table();
    dotnet_table::~dotnet_table();


public:
    void dotnet_table::set_major_version(WORD major_version);
    void dotnet_table::set_minor_version(WORD minor_version);

    void dotnet_table::set_flags(DWORD flags);
    void dotnet_table::set_entry_point(DWORD entry_point);

    void dotnet_table::set_meta_data(IMAGE_DATA_DIRECTORY meta_data);
    void dotnet_table::set_resources(IMAGE_DATA_DIRECTORY resources);
    void dotnet_table::set_strong_name_signature(IMAGE_DATA_DIRECTORY strong_name_signature);
    void dotnet_table::set_code_manager_table(IMAGE_DATA_DIRECTORY code_manager_table);
    void dotnet_table::set_vtable_fixups(IMAGE_DATA_DIRECTORY vtable_fixups);
    void dotnet_table::set_export_address_table_jumps(IMAGE_DATA_DIRECTORY export_address_table_jumps);
    void dotnet_table::set_managed_native_header(IMAGE_DATA_DIRECTORY managed_native_header);

public:
    WORD dotnet_table::get_major_version() const;
    WORD dotnet_table::get_minor_version() const;

    DWORD dotnet_table::get_flags() const;
    DWORD dotnet_table::get_entry_point() const;

    IMAGE_DATA_DIRECTORY dotnet_table::get_meta_data() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_resources() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_strong_name_signature() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_code_manager_table() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_vtable_fixups() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_export_address_table_jumps() const;
    IMAGE_DATA_DIRECTORY dotnet_table::get_managed_native_header() const;
};

bool get_dotnet_table(_In_ const pe_image &image, _Out_ dotnet_table& dotnet);