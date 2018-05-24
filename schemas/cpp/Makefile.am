lib_LIBRARIES = libocpb.a
bin_PROGRAMS = protogen cpp-gpb-proto

libocpb_a_SOURCES = \
	./github.com/openconfig/ygot/proto/yext/yext.pb.cc\
	./github.com/openconfig/ygot/proto/ywrapper/ywrapper.pb.cc\
	./openconfig/enums/enums.pb.cc\
	./openconfig/ietf_interfaces/ietf_interfaces.pb.cc\
	./openconfig/openconfig_access_points/openconfig_access_points.pb.cc\
	./openconfig/openconfig_acl/openconfig_acl.pb.cc\
	./openconfig/openconfig_ap_manager/openconfig_ap_manager.pb.cc\
	./openconfig/openconfig_channel_monitor/openconfig_channel_monitor.pb.cc\
	./openconfig/openconfig_interfaces/openconfig_interfaces.pb.cc\
	./openconfig/openconfig_lacp/openconfig_lacp.pb.cc\
	./openconfig/openconfig_lldp/openconfig_lldp.pb.cc\
	./openconfig/openconfig_module_catalog/openconfig_module_catalog.pb.cc\
	./openconfig/openconfig_optical_amplifier/openconfig_optical_amplifier.pb.cc\
	./openconfig/openconfig_platform/openconfig_platform.pb.cc\
	./openconfig/openconfig_probes/openconfig_probes.pb.cc\
	./openconfig/openconfig_qos/openconfig_qos.pb.cc\
	./openconfig/openconfig_relay_agent/openconfig_relay_agent.pb.cc\
	./openconfig/openconfig_spanning_tree/openconfig_spanning_tree.pb.cc\
	./openconfig/openconfig_system/openconfig_system.pb.cc\
	./openconfig/openconfig_telemetry/openconfig_telemetry.pb.cc\
	./openconfig/openconfig_terminal_device/openconfig_terminal_device.pb.cc\
	./openconfig/openconfig_transport_line_protection/openconfig_transport_line_protection.pb.cc\
	./openconfig/openconfig_wavelength_router/openconfig_wavelength_router.pb.cc\
	./openconfig/openconfig_wifi_mac/openconfig_wifi_mac.pb.cc\
	./openconfig/openconfig_wifi_phy/openconfig_wifi_phy.pb.cc

libocpb_a_CPPFLAGS = -I.
libocpb_a_CXXFLAGS = $(AM_CXXFLAGS) -O2

protogen_SOURCES = \
	proto_generator/main.cpp
protogen_CPPFLAGS = -I.
protogen_DEPENDENCIES = libocpb.a
protogen_LDADD = libocpb.a
protogen_LDFLAGS = $(AM_LDFLAGS) -lprotobuf

cpp_gpb_proto_SOURCES = \
	tester/main.cpp
cpp_gpb_proto_CPPFLAGS = -I.
cpp_gpb_proto_DEPENDENCIES = libocpb.a
cpp_gpb_proto_CXXFLAGS = $(AM_CXXFLAGS) -O2
cpp_gpb_proto_LDADD = libocpb.a
cpp_gpb_proto_LDFLAGS = $(AM_LDFLAGS) -lprotobuf
