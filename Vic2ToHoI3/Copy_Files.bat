copy "Data_Files\changelog.txt" "..\Release\Vic2ToHoI3\changelog.txt"
copy "Data_Files\configuration.txt" "..\Release\Vic2ToHoI3\configuration.txt"
copy "Data_Files\readme.txt" "..\Release\Vic2ToHoI3\readme.txt"
copy "Data_Files\merge_nations.txt" "..\Release\Vic2ToHoI3\merge_nations.txt"
copy "Data_Files\province_mappings.txt" "..\Release\Vic2ToHoI3\province_mappings.txt
copy "Data_Files\country_mappings.txt" "..\Release\Vic2ToHoI3\country_mappings.txt
copy "Data_Files\governmentMapping.txt" "..\Release\Vic2ToHoI3\governmentMapping.txt
copy "Data_Files\governmentJobs.txt" "..\Release\Vic2ToHoI3\governmentJobs.txt
copy "Data_Files\leader_traits.txt" "..\Release\Vic2ToHoI3\leader_traits.txt
copy "Data_Files\license.txt" "..\Release\Vic2ToHoI3\license.txt"
copy "Data_Files\tech_mapping.txt" "..\Release\Vic2ToHoI3\tech_mapping.txt"
copy "Data_Files\unit_mapping.txt" "..\Release\Vic2ToHoI3\unit_mapping.txt"
copy "Data_Files\portraits.txt" "..\Release\Vic2ToHoI3\portraits.txt"
copy "Data_Files\culture_map.txt" "..\Release\Vic2ToHoI3\culture_map.txt"
copy "Data_Files\personality_map.txt" "..\Release\Vic2ToHoI3\personality_map.txt"
copy "Data_Files\background_map.txt" "..\Release\Vic2ToHoI3\background_map.txt"
copy "Data_Files\FAQ.txt" "..\Release\Vic2ToHoI3\FAQ.txt"
copy "Data_Files\airTEMPLATE.lua" "..\Release\Vic2ToHoI3\airTEMPLATE.lua"
copy "Data_Files\autoexecTEMPLATE.lua" "..\Release\Vic2ToHoI3\autoexecTEMPLATE.lua"
copy "Data_Files\infatryTEMPLATE.lua" "..\Release\Vic2ToHoI3\infatryTEMPLATE.lua"
copy "Data_Files\shipTemplate.lua" "..\Release\Vic2ToHoI3\shipTemplate.lua"
copy "Data_Files\tankTemplate.lua" "..\Release\Vic2ToHoI3\tankTemplate.lua"
copy "Data_Files\ai_focus.txt" "..\Release\Vic2ToHoI3\ai_focus.txt"

del "..\Release\Vic2ToHoI3\changelog.txt
git log --oneline --decorate >> release/log.txt
(for /f "delims=" %%i in (release/log.txt) do @echo %%i)>release/changelog.txt
del "..\Release\Vic2ToHoI3\log.txt

del "..\Release\Vic2ToHoI3\blankMod" /Q
rmdir "..\Release\Vic2ToHoI3\blankMod" /S /Q
mkdir "..\Release\Vic2ToHoI3\blankMod"
mkdir "..\Release\Vic2ToHoI3\blankMod\output"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\provinces"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\countries"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\diplomacy"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\leaders"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\units"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\history\wars"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\events"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\decisions"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\script"
mkdir "..\Release\Vic2ToHoI3\blankMod\output\script\country"

xcopy "Data_Files\history\provinces" "..\Release\Vic2ToHoI3\blankmod\output\history\provinces" /Y /E /I
xcopy "Data_Files\countries" "..\Release\Vic2ToHoI3\blankmod\output\common\countries" /Y /E /I
xcopy "Data_files\localisation" "..\Release\Vic2ToHoI3\blankmod\output\localisation" /Y /E /I
xcopy "Data_files\script" "..\Release\Vic2ToHoI3\blankmod\output\script" /Y /E /I
copy "Data_Files\countries.txt" "..\Release\Vic2ToHoI3\blankMod\output\common\countries.txt"
copy "Data_Files\country_colors.txt" "..\Release\Vic2ToHoI3\blankMod\output\common\country_colors.txt"
xcopy "Data_files\wars" "..\Release\Vic2ToHoI3\blankmod\output\history\wars" /Y /E /I
xcopy "Data_Files\events" "..\Release\Vic2ToHoI3\blankMod\output\events"
xcopy "Data_Files\decisions" "..\Release\Vic2ToHoI3\blankMod\output\decisions"
copy "Data_Files\triggered_modifiers.txt" "..\Release\Vic2ToHoI3\blankMod\output\common\triggered_modifiers.txt"
copy "Data_Files\governments.txt" "..\Release\Vic2ToHoI3\blankMod\output\common\governments.txt"