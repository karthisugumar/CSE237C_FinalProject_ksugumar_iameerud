<project xmlns="com.autoesl.autopilot.project" name="maxpool_cnn" top="maxpool">
    <files>
        <file name="types.h" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
        <file name="maxpool_Alg.cpp" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
        <file name="../../conv1_out_7.dat" sc="0" tb="1" cflags=""/>
        <file name="../../maxpool_tb.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../../pool1_out_7.dat" sc="0" tb="1" cflags=""/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

