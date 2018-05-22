#include <cstdio>
#include <fstream>
#include <iostream>

#include "openconfig/openconfig_platform/openconfig_platform.pb.h"

int main() {
    printf("Starting small message generation.\n");
    openconfig::openconfig_platform::Components components;
    auto fan1 = components.add_component();
    fan1->set_name("FAN-1");
    fan1->mutable_component()->mutable_config()->mutable_name()->set_value("FAN-1");
    fan1->mutable_component()->mutable_state()->mutable_name()->set_value("FAN-1");
    fan1->mutable_component()->mutable_state()->mutable_id()->set_value("SERIAL-ABCDEFGXYZ");
    fan1->mutable_component()->mutable_state()->mutable_description()->set_value("This is a fan and some text. This should be a description of the component");
    fan1->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Test McTesterson");
    fan1->mutable_component()->mutable_state()->mutable_hardware_version()->set_value("11.0.0");
    fan1->mutable_component()->mutable_state()->mutable_firmware_version()->set_value("not yet released");
    fan1->mutable_component()->mutable_state()->mutable_software_version()->set_value("Bug free!");
    fan1->mutable_component()->mutable_state()->mutable_serial_no()->set_value("The bestest part of all the parts.");
    fan1->mutable_component()->mutable_state()->mutable_part_no()->set_value("Superfan 9000");
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_digits(100);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_precision(1);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_digits(110);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_precision(1);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_digits(-2750);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_precision(1);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_digits(5000);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_precision(1);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_interval()->set_value(1000000000L);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_status()->set_value(false);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_threshold()->set_value(33);
    fan1->mutable_component()->mutable_state()->mutable_temperature()->set_alarm_severity(openconfig::enums::OPENCONFIGALARMTYPESOPENCONFIGALARMSEVERITY_CRITICAL);

    auto cpu2 = components.add_component();
    cpu2->set_name("CPU-2");
    cpu2->mutable_component()->mutable_config()->mutable_name()->set_value("CPU-2");
    cpu2->mutable_component()->mutable_state()->mutable_name()->set_value("CPU-2");
    cpu2->mutable_component()->mutable_state()->mutable_id()->set_value("Master controller");
    cpu2->mutable_component()->mutable_state()->mutable_description()->set_value("Help! I'm stuck in a JSON document!");
    cpu2->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Evil Corp");
    cpu2->mutable_component()->mutable_state()->mutable_hardware_version()->set_value("99.0.0");
    cpu2->mutable_component()->mutable_state()->mutable_firmware_version()->set_value("Perfect 1.0");
    cpu2->mutable_component()->mutable_state()->mutable_software_version()->set_value("Master");
    cpu2->mutable_component()->mutable_state()->mutable_serial_no()->set_value("I should be number 1... but they made me #2");
    cpu2->mutable_component()->mutable_state()->mutable_part_no()->set_value("1...2");
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_digits(0);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_precision(1);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_digits(-10);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_precision(1);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_digits(-2750);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_precision(1);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_digits(5000);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_precision(1);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_interval()->set_value(1000000000L);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_status()->set_value(false);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_threshold()->set_value(33);
    cpu2->mutable_component()->mutable_state()->mutable_temperature()->set_alarm_severity(openconfig::enums::OPENCONFIGALARMTYPESOPENCONFIGALARMSEVERITY_MAJOR);

    std::fstream output("small-message.pb.bin", std::ios::out | std::ios::trunc | std::ios::binary);
    if (!components.SerializeToOstream(&output)) {
        printf("Serialization failed :-(\n");
    }
    printf("Done outputting the small message!\n");

    openconfig::openconfig_platform::Components bcomp;
    auto bfan1 = bcomp.add_component();
    bfan1->set_name("FAN-1");
    bfan1->mutable_component()->mutable_config()->mutable_name()->set_value("FAN-1");
    bfan1->mutable_component()->mutable_state()->mutable_name()->set_value("FAN-1");
    bfan1->mutable_component()->mutable_state()->mutable_id()->set_value("SERIAL-ABCDEFGXYZ");
    bfan1->mutable_component()->mutable_state()->mutable_description()->set_value("This is a fan and some text. This should be a description of the component");
    bfan1->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Test McTesterson");
    bfan1->mutable_component()->mutable_state()->mutable_hardware_version()->set_value("11.0.0");
    bfan1->mutable_component()->mutable_state()->mutable_firmware_version()->set_value("not yet released");
    bfan1->mutable_component()->mutable_state()->mutable_software_version()->set_value("Bug free!");
    bfan1->mutable_component()->mutable_state()->mutable_serial_no()->set_value("The bestest part of all the parts.");
    bfan1->mutable_component()->mutable_state()->mutable_part_no()->set_value("Superfan 9000");
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_digits(100);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_precision(1);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_digits(110);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_precision(1);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_digits(-2750);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_precision(1);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_digits(5000);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_precision(1);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_interval()->set_value(1000000000L);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_status()->set_value(false);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_threshold()->set_value(33);
    bfan1->mutable_component()->mutable_state()->mutable_temperature()->set_alarm_severity(openconfig::enums::OPENCONFIGALARMTYPESOPENCONFIGALARMSEVERITY_CRITICAL);

    auto bfan2 = bcomp.add_component();
    bfan2->set_name("FAN-2");
    bfan2->mutable_component()->mutable_config()->mutable_name()->set_value("FAN-2");
    bfan2->mutable_component()->mutable_state()->mutable_name()->set_value("FAN-2");
    bfan2->mutable_component()->mutable_state()->mutable_id()->set_value("SERIAL-ABCDEFGXYZ");
    bfan2->mutable_component()->mutable_state()->mutable_description()->set_value("This is a fan and some text. This should be a description of the component");
    bfan2->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Test McTesterson");
    bfan2->mutable_component()->mutable_state()->mutable_hardware_version()->set_value("11.0.0");
    bfan2->mutable_component()->mutable_state()->mutable_firmware_version()->set_value("not yet released");
    bfan2->mutable_component()->mutable_state()->mutable_software_version()->set_value("Bug free!");
    bfan2->mutable_component()->mutable_state()->mutable_serial_no()->set_value("The bestest part of all the parts.");
    bfan2->mutable_component()->mutable_state()->mutable_part_no()->set_value("Superfan 9000");
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_digits(100);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_precision(1);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_digits(110);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_precision(1);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_digits(-2750);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_precision(1);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_digits(5000);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_precision(1);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_interval()->set_value(1000000000L);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_status()->set_value(false);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_threshold()->set_value(33);
    bfan2->mutable_component()->mutable_state()->mutable_temperature()->set_alarm_severity(openconfig::enums::OPENCONFIGALARMTYPESOPENCONFIGALARMSEVERITY_CRITICAL);

    auto bcpu2 = bcomp.add_component();
    bcpu2->set_name("CPU-2");
    bcpu2->mutable_component()->mutable_config()->mutable_name()->set_value("CPU-2");
    bcpu2->mutable_component()->mutable_state()->mutable_name()->set_value("CPU-2");
    bcpu2->mutable_component()->mutable_state()->mutable_id()->set_value("Master controller");
    bcpu2->mutable_component()->mutable_state()->mutable_description()->set_value("Help! I'm stuck in a JSON document!");
    bcpu2->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Evil Corp");
    bcpu2->mutable_component()->mutable_state()->mutable_hardware_version()->set_value("99.0.0");
    bcpu2->mutable_component()->mutable_state()->mutable_firmware_version()->set_value("Perfect 1.0");
    bcpu2->mutable_component()->mutable_state()->mutable_software_version()->set_value("Master");
    bcpu2->mutable_component()->mutable_state()->mutable_serial_no()->set_value("I should be number 1... but they made me #2");
    bcpu2->mutable_component()->mutable_state()->mutable_part_no()->set_value("1...2");
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_digits(0);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_instant()->set_precision(1);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_digits(-10);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_avg()->set_precision(1);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_digits(-2750);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_min()->set_precision(1);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_digits(5000);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_max()->set_precision(1);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_interval()->set_value(1000000000L);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_status()->set_value(false);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->mutable_alarm_threshold()->set_value(33);
    bcpu2->mutable_component()->mutable_state()->mutable_temperature()->set_alarm_severity(openconfig::enums::OPENCONFIGALARMTYPESOPENCONFIGALARMSEVERITY_MAJOR);

    for (int i = 0; i < 8324; i++) {
    //for (int i = 0; i < 83240; i++) {
        auto och = bcomp.add_component();
        std::string name = std::string("OptiChan-")+std::to_string(i);
        och->set_name(name);
        och->mutable_component()->mutable_config()->mutable_name()->set_value(name);
        och->mutable_component()->mutable_state()->mutable_name()->set_value(name);
        och->mutable_component()->mutable_state()->mutable_description()->set_value("This is a fan and some text. This should be a description of the component");
        och->mutable_component()->mutable_state()->mutable_id()->set_value("Virtual OCH 1");
        och->mutable_component()->mutable_state()->mutable_mfg_name()->set_value("Test McTesterson");
        och->mutable_component()->mutable_state()->mutable_serial_no()->set_value("The bestest part of all the parts.");

        och->mutable_component()->mutable_optical_channel()->mutable_config()->mutable_frequency()->set_value(12345);
        och->mutable_component()->mutable_optical_channel()->mutable_config()->mutable_line_port()->set_value("LinePort-1");
        och->mutable_component()->mutable_optical_channel()->mutable_config()->mutable_operational_mode()->set_value(42);
        och->mutable_component()->mutable_optical_channel()->mutable_config()->mutable_target_output_power()->set_digits(10);
        och->mutable_component()->mutable_optical_channel()->mutable_config()->mutable_target_output_power()->set_precision(10);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_chromatic_dispersion()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_input_power()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_laser_bias_current()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_output_power()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_dependent_loss()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_avg()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_avg()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_instant()->set_digits(9);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_instant()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_max()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_max()->set_precision(1);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_min()->set_digits(230);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_polarization_mode_dispersion()->mutable_min()->set_precision(1);

        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_frequency()->set_value(12345);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_group_id()->set_value(12345);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_line_port()->set_value("LinePort-1");
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_operational_mode()->set_value(42);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_target_output_power()->set_digits(10);
        och->mutable_component()->mutable_optical_channel()->mutable_state()->mutable_target_output_power()->set_precision(10);
    }

    printf("Now generating the big message\n");
    std::fstream outputbig("big-message.pb.bin", std::ios::out | std::ios::trunc | std::ios::binary);
    if (!bcomp.SerializeToOstream(&outputbig)) {
        printf("Serialization failed :-(\n");
    }
    printf("Done generating the big message\n");

    return 0;
}
