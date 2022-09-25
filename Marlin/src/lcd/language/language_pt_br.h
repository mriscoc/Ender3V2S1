/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Portuguese (Brazil)
 * UTF-8 for Graphical Display
 *
 * LCD Menu Messages
 * See also https://marlinfw.org/docs/development/lcd_language.html
 */

namespace Language_pt_br {
  using namespace Language_en; // Inherit undefined strings from English

  constexpr uint8_t CHARSIZE              = 2;
  LSTR LANGUAGE                           = _UxGT("Portuguese (BR)");


  // These strings should be translated
  LSTR WELCOME_MSG                        = MACHINE_NAME _UxGT(" Pronta");
  LSTR MSG_YES                            = _UxGT("SIM");
  LSTR MSG_NO                             = _UxGT("NAO");
  LSTR MSG_HIGH                           = _UxGT("ALTO");
  LSTR MSG_LOW                            = _UxGT("BAIXO");
  LSTR MSG_BACK                           = _UxGT("Voltar");
  LSTR MSG_ERROR                          = _UxGT("Erro");
  LSTR MSG_MEDIA_ABORTING                 = _UxGT("Abortando...");
  LSTR MSG_MEDIA_INSERTED                 = _UxGT("Cartao inserido");
  LSTR MSG_MEDIA_REMOVED                  = _UxGT("Cartao removido");
  LSTR MSG_MEDIA_WAITING                  = _UxGT("Aguardando por cartao SD");
  LSTR MSG_MEDIA_INIT_FAIL                = _UxGT(" Falha ao iniciar SD/FD");
  LSTR MSG_MEDIA_READ_ERROR               = _UxGT(" Erro de leitura");
  LSTR MSG_MEDIA_USB_REMOVED              = _UxGT("Disp. USB removido");
  LSTR MSG_MEDIA_USB_FAILED               = _UxGT("Falha ao iniciar USB");
  LSTR MSG_KILL_SUBCALL_OVERFLOW          = _UxGT("Estouro de subchamada");
  LSTR MSG_LCD_ENDSTOPS                   = _UxGT("Finais"); // Max length 8 characters
  LSTR MSG_LCD_SOFT_ENDSTOPS              = _UxGT("Soft Endstops");
  LSTR MSG_MAIN                           = _UxGT("Menu Principal");
  LSTR MSG_ADVANCED_SETTINGS              = _UxGT("Ajustes avancados");
  LSTR MSG_TOOLBAR_SETUP                  = _UxGT("Config. Toolbar");
  LSTR MSG_OPTION_DISABLED                = _UxGT("Opcao desativada");
  LSTR MSG_CONFIGURATION                  = _UxGT("Configuracao");
  LSTR MSG_RUN_AUTO_FILES                 = _UxGT("Executar arquivos automaticos");
  LSTR MSG_DISABLE_STEPPERS               = _UxGT("Desab. motores");
  LSTR MSG_DEBUG_MENU                     = _UxGT("Menu debug");
  LSTR MSG_PROGRESS_BAR_TEST              = _UxGT("Testar barra de prog");
  LSTR MSG_HOMING                         = _UxGT("Origem");
  LSTR MSG_AUTO_HOME                      = _UxGT("Auto origem");
  LSTR MSG_AUTO_HOME_A                    = _UxGT("Origem @");
  LSTR MSG_AUTO_HOME_X                    = _UxGT("Ir na origem X");
  LSTR MSG_AUTO_HOME_Y                    = _UxGT("Ir na origem Y");
  LSTR MSG_AUTO_HOME_Z                    = _UxGT("Ir na origem Z");
  LSTR MSG_Z_AFTER_HOME                   = _UxGT("Z apos Homming");
  LSTR MSG_FILAMENT_SET                   = _UxGT("Config. Filamento");
  LSTR MSG_FILAMENT_MAN                   = _UxGT("Gerenciar filamento");
  LSTR MSG_MANUAL_LEVELING                = _UxGT("Nivelamento manual");
  LSTR MSG_LEVBED_FL                      = _UxGT("Frente esquerdo");
  LSTR MSG_LEVBED_FR                      = _UxGT("Frente direito");
  LSTR MSG_LEVBED_C                       = _UxGT("Centro");
  LSTR MSG_LEVBED_BL                      = _UxGT("Fundo esquerdo");
  LSTR MSG_LEVBED_BR                      = _UxGT("Fundo direito");
  LSTR MSG_MANUAL_MESH                    = _UxGT("Malha manual");
  LSTR MSG_AUTO_MESH                      = _UxGT("Malha automatica");
  LSTR MSG_AUTO_Z_ALIGN                   = _UxGT("Auto alinhar Z");
  LSTR MSG_ITERATION                      = _UxGT("G34 Iteracao: %i");
  LSTR MSG_DECREASING_ACCURACY            = _UxGT("Precisao diminuindo!");
  LSTR MSG_ACCURACY_ACHIEVED              = _UxGT("Precisao atingida");
  LSTR MSG_LEVEL_BED_HOMING               = _UxGT("Ir na origem XYZ");
  LSTR MSG_LEVEL_BED_WAITING              = _UxGT("Click para iniciar");
  LSTR MSG_LEVEL_BED_NEXT_POINT           = _UxGT("Proximo ponto");
  LSTR MSG_LEVEL_BED_DONE                 = _UxGT("Nivelamento concluido!");
  LSTR MSG_Z_FADE_HEIGHT                  = _UxGT("Suavizar altura");
  LSTR MSG_SET_HOME_OFFSETS               = _UxGT("Compensar origem");
  LSTR MSG_HOME_OFFSET_X                  = _UxGT("Desloc. inicial X");
  LSTR MSG_HOME_OFFSET_Y                  = _UxGT("Desloc. inicial Y");
  LSTR MSG_HOME_OFFSET_Z                  = _UxGT("Desloc. inicial Z");
  LSTR MSG_HOME_OFFSETS_APPLIED           = _UxGT("Compensacoes aplicadas");
  LSTR MSG_TRAMMING_WIZARD                = _UxGT("Assistente de Tramming");
  LSTR MSG_SELECT_ORIGIN                  = _UxGT("Selecionar origem");
  LSTR MSG_LAST_VALUE_SP                  = _UxGT("Ultimo valor ");
  #if HAS_PREHEAT
    LSTR MSG_PREHEAT_1                    = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL;
    LSTR MSG_PREHEAT_1_H                  = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL " ~";
    LSTR MSG_PREHEAT_1_END                = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL _UxGT(" Fim");
    LSTR MSG_PREHEAT_1_END_E              = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL _UxGT(" Fim ~");
    LSTR MSG_PREHEAT_1_ALL                = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL _UxGT(" Tudo");
    LSTR MSG_PREHEAT_1_BEDONLY            = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL _UxGT(" Mesa");
    LSTR MSG_PREHEAT_1_SETTINGS           = _UxGT("Pre-aquecer ") PREHEAT_1_LABEL _UxGT(" Conf");
    #ifdef PREHEAT_2_LABEL
      LSTR MSG_PREHEAT_2                  = _UxGT("Pre-aquecer ") PREHEAT_2_LABEL;
      LSTR MSG_PREHEAT_2_SETTINGS         = _UxGT("Pre-aquecer ") PREHEAT_2_LABEL _UxGT(" Conf");
    #endif
    #ifdef PREHEAT_3_LABEL
      LSTR MSG_PREHEAT_3                  = _UxGT("Pre-aquecer ") PREHEAT_3_LABEL;
      LSTR MSG_PREHEAT_3_SETTINGS         = _UxGT("Pre-aquecer ") PREHEAT_3_LABEL _UxGT(" Conf");
    #endif
    LSTR MSG_PREHEAT_M                    = _UxGT("Pre-aquecer $");
    LSTR MSG_PREHEAT_M_H                  = _UxGT("Pre-aquecer $ ~");
    LSTR MSG_PREHEAT_M_END                = _UxGT("Pre-aquecer $ Fim");
    LSTR MSG_PREHEAT_M_END_E              = _UxGT("Pre-aquecer $ Fim ~");
    LSTR MSG_PREHEAT_M_ALL                = _UxGT("Pre-aquecer $ Tudo");
    LSTR MSG_PREHEAT_M_BEDONLY            = _UxGT("Pre-aquecer $ Mesa");
    LSTR MSG_PREHEAT_M_SETTINGS           = _UxGT("Pre-aquecer $ Conf");
  #endif
  LSTR MSG_PREHEAT_CUSTOM                 = _UxGT("Pre-aquecer person.");
  LSTR MSG_COOLDOWN                       = _UxGT("Resfriar");

  LSTR MSG_CUTTER_FREQUENCY               = _UxGT("Frequencia");
  LSTR MSG_LASER_MENU                     = _UxGT("Laser Control");
  LSTR MSG_SPINDLE_MENU                   = _UxGT("Spindle Control");
  LSTR MSG_LASER_POWER                    = _UxGT("Laser Power");
  LSTR MSG_SPINDLE_POWER                  = _UxGT("Spindle Pwr");
  LSTR MSG_LASER_TOGGLE                   = _UxGT("Toggle Laser");
  LSTR MSG_LASER_EVAC_TOGGLE              = _UxGT("Toggle Blower");
  LSTR MSG_LASER_ASSIST_TOGGLE            = _UxGT("Air Assist");
  LSTR MSG_LASER_PULSE_MS                 = _UxGT("Test Pulse ms");
  LSTR MSG_LASER_FIRE_PULSE               = _UxGT("Fire Pulse");
  LSTR MSG_FLOWMETER_FAULT                = _UxGT("Coolant Flow Fault");
  LSTR MSG_SPINDLE_TOGGLE                 = _UxGT("Toggle Spindle");
  LSTR MSG_SPINDLE_EVAC_TOGGLE            = _UxGT("Toggle Vacuum");
  LSTR MSG_SPINDLE_FORWARD                = _UxGT("Spindle Forward");
  LSTR MSG_SPINDLE_REVERSE                = _UxGT("Spindle Reverse");
  LSTR MSG_SWITCH_PS_ON                   = _UxGT("Switch Power On");
  LSTR MSG_SWITCH_PS_OFF                  = _UxGT("Switch Power Off");
  LSTR MSG_EXTRUDE                        = _UxGT("Extrusar");
  LSTR MSG_RETRACT                        = _UxGT("Retrair");
  LSTR MSG_MOVE_AXIS                      = _UxGT("Mover eixo");
  LSTR MSG_BED_LEVELING                   = _UxGT("Nivelando a mesa");
  LSTR MSG_LEVEL_BED                      = _UxGT("Nivelar mesa");
  LSTR MSG_BED_TRAMMING                   = _UxGT("Malha da mesa");
  LSTR MSG_BED_TRAMMING_MANUAL            = _UxGT("Malha manual");
  LSTR MSG_BED_TRAMMING_RAISE             = _UxGT("Ajuste a mesa ate que a sonda seja acionada.");
  LSTR MSG_BED_TRAMMING_IN_RANGE          = _UxGT("Cantos dentro da tolerancia. Mesa nivelada");
  LSTR MSG_BED_TRAMMING_GOOD_POINTS       = _UxGT("Pontos bons: ");
  LSTR MSG_BED_TRAMMING_LAST_Z            = _UxGT("Ultimo Z: ");
  LSTR MSG_NEXT_CORNER                    = _UxGT("Proximo canto");
  LSTR MSG_MESH_EDITOR                    = _UxGT("Editor de malha");
  LSTR MSG_MESH_VIEWER                    = _UxGT("Visualizador de malha");
  LSTR MSG_EDIT_MESH                      = _UxGT("Editar Malha");
  LSTR MSG_MESH_VIEW                      = _UxGT("Ver malha");
  LSTR MSG_EDITING_STOPPED                = _UxGT("Edicao de malha parado");
  LSTR MSG_NO_VALID_MESH                  = _UxGT("Nenhuma malha valida");
  LSTR MSG_ACTIVATE_MESH                  = _UxGT("Ativar UBL");
  LSTR MSG_PROBING_POINT                  = _UxGT("Teste do ponto");
  LSTR MSG_MESH_X                         = _UxGT("Malha X");
  LSTR MSG_MESH_Y                         = _UxGT("Malha Y");
  LSTR MSG_MESH_INSET                     = _UxGT("Insercao de malha");
  LSTR MSG_MESH_MIN_X                     = _UxGT("Malha X Minimo");
  LSTR MSG_MESH_MAX_X                     = _UxGT("Malha X Maximo");
  LSTR MSG_MESH_MIN_Y                     = _UxGT("Malha Y Minimo");
  LSTR MSG_MESH_MAX_Y                     = _UxGT("Malha Y Maximo");
  LSTR MSG_MESH_AMAX                      = _UxGT("Maximiza area");
  LSTR MSG_MESH_CENTER                    = _UxGT("Area Central");
  LSTR MSG_MESH_EDIT_Z                    = _UxGT("Valor Z");
  LSTR MSG_MESH_CANCEL                    = _UxGT("Malha cancelada");
  LSTR MSG_CUSTOM_COMMANDS                = _UxGT("Comandos customizados");
  LSTR MSG_M48_TEST                       = _UxGT("Teste M48");
  LSTR MSG_M48_POINT                      = _UxGT("Ponto M48");
  LSTR MSG_M48_OUT_OF_BOUNDS              = _UxGT("Sonda fora dos limites");
  LSTR MSG_M48_DEVIATION                  = _UxGT("Derivacao");
  LSTR MSG_IDEX_MENU                      = _UxGT("Modo IDEX");
  LSTR MSG_OFFSETS_MENU                   = _UxGT("Ferramenta compensacao");
  LSTR MSG_IDEX_MODE_AUTOPARK             = _UxGT("Estacionamento automatico");
  LSTR MSG_IDEX_MODE_DUPLICATE            = _UxGT("Duplicacao");
  LSTR MSG_IDEX_MODE_MIRRORED_COPY        = _UxGT("Copia espelhada");
  LSTR MSG_IDEX_MODE_FULL_CTRL            = _UxGT("Controle total");
  LSTR MSG_IDEX_DUPE_GAP                  = _UxGT("X-Gap duplicado");
  LSTR MSG_HOTEND_OFFSET_Z                = _UxGT("2º bico Z");
  LSTR MSG_HOTEND_OFFSET_A                = _UxGT("2º bico @");
  LSTR MSG_UBL_DOING_G29                  = _UxGT("Fazendo G29");
  LSTR MSG_UBL_TOOLS                      = _UxGT("Ferramenta UBL");
  LSTR MSG_UBL_LEVEL_BED                  = _UxGT("Nivelamento de mesa");
  LSTR MSG_LCD_TILTING_MESH               = _UxGT("Ponto de inclinacao");
  LSTR MSG_UBL_TILT_MESH                  = _UxGT("Inclinar Malha");
  LSTR MSG_UBL_TILTING_GRID               = _UxGT("Incrinacao do tamanho da grade");
  LSTR MSG_UBL_MESH_TILTED                = _UxGT("Malha inclinada");
  LSTR MSG_UBL_MANUAL_MESH                = _UxGT("Criar malha manualmente");
  LSTR MSG_UBL_MESH_WIZARD                = _UxGT("Assistente de malha UBL");
  LSTR MSG_UBL_BC_INSERT                  = _UxGT("Colocar calco e medir");
  LSTR MSG_UBL_BC_INSERT2                 = _UxGT("Medida");
  LSTR MSG_UBL_BC_REMOVE                  = _UxGT("Remover e medir a mesa");
  LSTR MSG_UBL_MOVING_TO_NEXT             = _UxGT("Movendo para prox.");
  LSTR MSG_UBL_ACTIVATE_MESH              = _UxGT("Ativar UBL");
  LSTR MSG_UBL_DEACTIVATE_MESH            = _UxGT("Desativar UBL");
  LSTR MSG_UBL_SET_TEMP_BED               = _UxGT("Temp. Mesa");
  LSTR MSG_UBL_BED_TEMP_CUSTOM            = _UxGT("Temp. Mesa");
  LSTR MSG_UBL_SET_TEMP_HOTEND            = _UxGT("Temp. Hotend");
  LSTR MSG_UBL_HOTEND_TEMP_CUSTOM         = _UxGT("Temp. Hotend");
  LSTR MSG_UBL_MESH_EDIT                  = _UxGT("Editar Malha");
  LSTR MSG_UBL_EDIT_CUSTOM_MESH           = _UxGT("Editar Malha custom.");
  LSTR MSG_UBL_FINE_TUNE_MESH             = _UxGT("Ajuste fino da malha");
  LSTR MSG_UBL_DONE_EDITING_MESH          = _UxGT("Edicao de malha conluida");
  LSTR MSG_UBL_BUILD_CUSTOM_MESH          = _UxGT("Criar malha person.");
  LSTR MSG_UBL_BUILD_MESH_MENU            = _UxGT("Criar Malha");
  LSTR MSG_UBL_BUILD_MESH_M               = _UxGT("Criar Malha ($)");
  LSTR MSG_UBL_BUILD_COLD_MESH            = _UxGT("Criar malha a frio");
  LSTR MSG_UBL_MESH_HEIGHT_ADJUST         = _UxGT("Ajustar a altura da malha");
  LSTR MSG_UBL_MESH_HEIGHT_AMOUNT         = _UxGT("Height Amount");
  LSTR MSG_UBL_VALIDATE_MESH_MENU         = _UxGT("Validar Malha");
  LSTR MSG_UBL_VALIDATE_MESH_M            = _UxGT("Validar Malha ($)");
  LSTR MSG_UBL_VALIDATE_CUSTOM_MESH       = _UxGT("Validar Malha custom");
  LSTR MSG_G26_HEATING_BED                = _UxGT("G26 Aquecendo mesa");
  LSTR MSG_G26_HEATING_NOZZLE             = _UxGT("G26 Aquecendo Ext.");
  LSTR MSG_G26_MANUAL_PRIME               = _UxGT("Escorvamento Manual...");
  LSTR MSG_G26_FIXED_LENGTH               = _UxGT("Fixed Length Prime");
  LSTR MSG_G26_PRIME_DONE                 = _UxGT("Escorvamento pronto");
  LSTR MSG_G26_CANCELED                   = _UxGT("G26 Cancelado");
  LSTR MSG_G26_LEAVING                    = _UxGT("Saindo G26");
  LSTR MSG_UBL_CONTINUE_MESH              = _UxGT("Continua malha da mesa");
  LSTR MSG_UBL_MESH_LEVELING              = _UxGT("Nivelamento da malha");
  LSTR MSG_UBL_3POINT_MESH_LEVELING       = _UxGT("Nivelando 3º ponto");
  LSTR MSG_UBL_GRID_MESH_LEVELING         = _UxGT("Nivelando grade");
  LSTR MSG_UBL_MESH_LEVEL                 = _UxGT("Nivelar malha");
  LSTR MSG_UBL_SIDE_POINTS                = _UxGT("Cantos");
  LSTR MSG_UBL_MAP_TYPE                   = _UxGT("Tipo de mapa");
  LSTR MSG_UBL_OUTPUT_MAP                 = _UxGT("Salvar mapa da malha");
  LSTR MSG_UBL_OUTPUT_MAP_HOST            = _UxGT("Enviar para host");
  LSTR MSG_UBL_OUTPUT_MAP_CSV             = _UxGT("Salvar para CSV");
  LSTR MSG_UBL_OUTPUT_MAP_BACKUP          = _UxGT("Salvar backup");
  LSTR MSG_UBL_INFO_UBL                   = _UxGT("Informacao do UBL");
  LSTR MSG_UBL_FILLIN_AMOUNT              = _UxGT("Quantidade de enchimento");
  LSTR MSG_UBL_MANUAL_FILLIN              = _UxGT("Enchimento manual");
  LSTR MSG_UBL_SMART_FILLIN               = _UxGT("Enchimento Smart");
  LSTR MSG_UBL_FILLIN_MESH                = _UxGT("preencher malha");
  LSTR MSG_UBL_MESH_FILLED                = _UxGT("Pontos ausentes prenchidos");
  LSTR MSG_UBL_MESH_INVALID               = _UxGT("Malha invalida");
  LSTR MSG_UBL_INVALIDATE_ALL             = _UxGT("Invalidar tudo");
  LSTR MSG_UBL_INVALIDATE_CLOSEST         = _UxGT("Invalidar proximo");
  LSTR MSG_UBL_FINE_TUNE_ALL              = _UxGT("Ajuste fino de todos");
  LSTR MSG_UBL_FINE_TUNE_CLOSEST          = _UxGT("Ajustar mais proximo");
  LSTR MSG_UBL_STORAGE_MESH_MENU          = _UxGT("Armazenar malha");
  LSTR MSG_UBL_STORAGE_SLOT               = _UxGT("Slot de memoria");
  LSTR MSG_UBL_LOAD_MESH                  = _UxGT("Ler malha");
  LSTR MSG_UBL_SAVE_MESH                  = _UxGT("Salvar malha");
  LSTR MSG_UBL_INVALID_SLOT               = _UxGT("Primeiro selecione um slot de malha");
  LSTR MSG_MESH_LOADED                    = _UxGT("Malha %i carregada");
  LSTR MSG_MESH_SAVED                     = _UxGT("Malha %i salva");
  LSTR MSG_MESH_ACTIVE                    = _UxGT("Malha %i ativa");
  LSTR MSG_UBL_NO_STORAGE                 = _UxGT("Sem armazenamento");
  LSTR MSG_UBL_SAVE_ERROR                 = _UxGT("Erro ao salvar UBL");
  LSTR MSG_UBL_RESTORE_ERROR              = _UxGT("Erro restaurar UBL");
  LSTR MSG_UBL_Z_OFFSET                   = _UxGT("Compensacao Z: ");
  LSTR MSG_UBL_Z_OFFSET_STOPPED           = _UxGT("Compensacao Z parou");
  LSTR MSG_UBL_STEP_BY_STEP_MENU          = _UxGT("UBL passo a passo");
  LSTR MSG_UBL_1_BUILD_COLD_MESH          = _UxGT("1. Construir malha fria");
  LSTR MSG_UBL_2_SMART_FILLIN             = _UxGT("2. Enchimento Smart");
  LSTR MSG_UBL_3_VALIDATE_MESH_MENU       = _UxGT("3. Validar malha");
  LSTR MSG_UBL_4_FINE_TUNE_ALL            = _UxGT("4. Ajuste Fino de Todos");
  LSTR MSG_UBL_5_VALIDATE_MESH_MENU       = _UxGT("5. Validar Malha");
  LSTR MSG_UBL_6_FINE_TUNE_ALL            = _UxGT("6. Ajuste Fino de Todos");
  LSTR MSG_UBL_7_SAVE_MESH                = _UxGT("7. Salvar Malha");

  LSTR MSG_LED_CONTROL                    = _UxGT("Controle do LED");
  LSTR MSG_LEDS                           = _UxGT("Luz");
  LSTR MSG_LED_PRESETS                    = _UxGT("Configuracao da Luz");
  LSTR MSG_SET_LEDS_RED                   = _UxGT("Vermelho");
  LSTR MSG_SET_LEDS_ORANGE                = _UxGT("Laranja");
  LSTR MSG_SET_LEDS_YELLOW                = _UxGT("Amarelo");
  LSTR MSG_SET_LEDS_GREEN                 = _UxGT("Verde");
  LSTR MSG_SET_LEDS_BLUE                  = _UxGT("Azul");
  LSTR MSG_SET_LEDS_INDIGO                = _UxGT("Indigo");
  LSTR MSG_SET_LEDS_VIOLET                = _UxGT("Violeta");
  LSTR MSG_SET_LEDS_WHITE                 = _UxGT("Branco");
  LSTR MSG_SET_LEDS_DEFAULT               = _UxGT("Padrao");
  LSTR MSG_LED_CHANNEL_N                  = _UxGT("Canal =");
  LSTR MSG_LEDS2                          = _UxGT("Luz #2");
  LSTR MSG_NEO2_PRESETS                   = _UxGT("Ajuste de luz #2");
  LSTR MSG_NEO2_BRIGHTNESS                = _UxGT("Brilho");
  LSTR MSG_CUSTOM_LEDS                    = _UxGT("Luz custom.");
  LSTR MSG_INTENSITY_R                    = _UxGT("Intensidade Vermelho");
  LSTR MSG_INTENSITY_G                    = _UxGT("Intensidade Verde");
  LSTR MSG_INTENSITY_B                    = _UxGT("Intensidade Azul");
  LSTR MSG_INTENSITY_W                    = _UxGT("Intensidade Branco");
  LSTR MSG_LED_BRIGHTNESS                 = _UxGT("Brilho");

  LSTR MSG_MOVING                         = _UxGT("Movendo...");
  LSTR MSG_FREE_XY                        = _UxGT("Liberar XY");
  LSTR MSG_MOVE_X                         = _UxGT("Mover X"); // Used by draw_edit_screen
  LSTR MSG_MOVE_Y                         = _UxGT("Mover Y");
  LSTR MSG_MOVE_Z                         = _UxGT("Mover Z");
  LSTR MSG_MOVE_N                         = _UxGT("Mover @");
  LSTR MSG_MOVE_E                         = _UxGT("Mover Extrusor");
  LSTR MSG_MOVE_EN                        = _UxGT("Mover *");
  LSTR MSG_HOTEND_TOO_COLD                = _UxGT("Hotend muito frio");
  LSTR MSG_MOVE_N_MM                      = _UxGT("Mover $mm");
  LSTR MSG_MOVE_01MM                      = _UxGT("Mover 0.1mm");
  LSTR MSG_MOVE_1MM                       = _UxGT("Mover 1mm");
  LSTR MSG_MOVE_10MM                      = _UxGT("Mover 10mm");
  LSTR MSG_MOVE_100MM                     = _UxGT("Mover 100mm");
  LSTR MSG_MOVE_0001IN                    = _UxGT("Mover 0.001in");
  LSTR MSG_MOVE_001IN                     = _UxGT("Mover 0.01in");
  LSTR MSG_MOVE_01IN                      = _UxGT("Mover 0.1in");
  LSTR MSG_MOVE_1IN                       = _UxGT("Mover 1.0in");
  LSTR MSG_SPEED                          = _UxGT("Velocidade");
  LSTR MSG_BED_Z                          = _UxGT("Base Z");
  LSTR MSG_NOZZLE                         = _UxGT("Bocal");
  LSTR MSG_NOZZLE_N                       = _UxGT("Bocal ~");
  LSTR MSG_NOZZLE_PARKED                  = _UxGT("Bocal parado");
  LSTR MSG_NOZZLE_STANDBY                 = _UxGT("Bocal aguardando");
  LSTR MSG_NOOZLE_CLEAN                   = _UxGT("Limpe e aperte continuar");
  LSTR MSG_BED                            = _UxGT("Mesa");
  LSTR MSG_CHAMBER                        = _UxGT("Involucro");
  LSTR MSG_COOLER                         = _UxGT("Refrigeracao Laser");
  LSTR MSG_COOLER_TOGGLE                  = _UxGT("Alternar refrigeracao");
  LSTR MSG_FLOWMETER_SAFETY               = _UxGT("Fluxo seguro");
  LSTR MSG_LASER                          = _UxGT("Laser");
  LSTR MSG_FAN_SPEED                      = _UxGT("Velocidade Fan");
  LSTR MSG_FAN_SPEED_N                    = _UxGT("Velocidade Fan ~");
  LSTR MSG_STORED_FAN_N                   = _UxGT("Fan armazenado ~");
  LSTR MSG_EXTRA_FAN_SPEED                = _UxGT("Velocidade Extra Fan");
  LSTR MSG_EXTRA_FAN_SPEED_N              = _UxGT("Velocidade Extra Fan ~");
  LSTR MSG_CONTROLLER_FAN                 = _UxGT("Controlador Fan");
  LSTR MSG_CONTROLLER_FAN_IDLE_SPEED      = _UxGT("Idle Speed");
  LSTR MSG_CONTROLLER_FAN_AUTO_ON         = _UxGT("Modo auto");
  LSTR MSG_CONTROLLER_FAN_SPEED           = _UxGT("Veloc. ativa");
  LSTR MSG_CONTROLLER_FAN_DURATION        = _UxGT("Idle Period");
  LSTR MSG_FLOW                           = _UxGT("Fluxo");
  LSTR MSG_FLOW_N                         = _UxGT("Fluxo ~");
  LSTR MSG_CONTROL                        = _UxGT("Controle");
  LSTR MSG_MIN                            = " " LCD_STR_THERMOMETER _UxGT(" Min");
  LSTR MSG_MAX                            = " " LCD_STR_THERMOMETER _UxGT(" Max");
  LSTR MSG_FACTOR                         = " " LCD_STR_THERMOMETER _UxGT(" Fact");
  LSTR MSG_AUTOTEMP                       = _UxGT("Temp. Automatica");
  LSTR MSG_LCD_ON                         = _UxGT("Ligado");
  LSTR MSG_LCD_OFF                        = _UxGT("Desligado");
  LSTR MSG_PID_AUTOTUNE                   = _UxGT("Ajuste automatico de PID");
  LSTR MSG_PID_AUTOTUNE_E                 = _UxGT("Ajuste automatico de PID *");
  LSTR MSG_PID_CYCLE                      = _UxGT("Ciclos PID");
  LSTR MSG_PID_AUTOTUNE_DONE              = _UxGT("Ajuste PID pronto");
  LSTR MSG_PID_AUTOTUNE_FAILED            = _UxGT("Ajuste PID falhou!");
  LSTR MSG_BAD_EXTRUDER_NUM               = _UxGT("Extrusora ruim.");
  LSTR MSG_TEMP_TOO_HIGH                  = _UxGT("Temperatura muito alta.");
  LSTR MSG_TIMEOUT                        = _UxGT("Timeout.");
  LSTR MSG_PID_BAD_EXTRUDER_NUM           = _UxGT("Auto-ajuste falhou! Extrusora ruim.");
  LSTR MSG_PID_TEMP_TOO_HIGH              = _UxGT("Auto-ajuste falhou! Temperatura muito alta.");
  LSTR MSG_PID_TIMEOUT                    = _UxGT("Auto-ajuste falhou! Timeout.");
  LSTR MSG_MPC_MEASURING_AMBIENT          = _UxGT("Testando perda de calor");
  LSTR MSG_MPC_AUTOTUNE                   = _UxGT("MPC auto-ajuste");
  LSTR MSG_MPC_EDIT                       = _UxGT("Editar * MPC");
  LSTR MSG_MPC_POWER                      = _UxGT("Potencia aquecedor");
  LSTR MSG_MPC_POWER_E                    = _UxGT("Potencia *");
  LSTR MSG_MPC_BLOCK_HEAT_CAPACITY        = _UxGT("Capacidade bloqueada");
  LSTR MSG_MPC_BLOCK_HEAT_CAPACITY_E      = _UxGT("Block C *");
  LSTR MSG_SENSOR_RESPONSIVENESS          = _UxGT("Sensor respons.");
  LSTR MSG_SENSOR_RESPONSIVENESS_E        = _UxGT("Sensor res *");
  LSTR MSG_MPC_AMBIENT_XFER_COEFF         = _UxGT("Ambient xfer c.");
  LSTR MSG_MPC_AMBIENT_XFER_COEFF_E       = _UxGT("Ambient h *");
  LSTR MSG_MPC_AMBIENT_XFER_COEFF_FAN     = _UxGT("Amb. fan xfer c.");
  LSTR MSG_MPC_AMBIENT_XFER_COEFF_FAN_E   = _UxGT("Amb. h fan *");
  LSTR MSG_SELECT                         = _UxGT("Select");
  LSTR MSG_SELECT_E                       = _UxGT("Select *");
  LSTR MSG_ACC                            = _UxGT("Acel.");
  LSTR MSG_JERK                           = _UxGT("Jerk");
  LSTR MSG_VA_JERK                        = _UxGT("Max ") STR_A _UxGT(" Jogo");
  LSTR MSG_VB_JERK                        = _UxGT("Max ") STR_B _UxGT(" Jogo");
  LSTR MSG_VC_JERK                        = _UxGT("Max ") STR_C _UxGT(" Jogo");
  LSTR MSG_VN_JERK                        = _UxGT("Max @ Jogo");
  LSTR MSG_VE_JERK                        = _UxGT("Max E Jogo");
  LSTR MSG_JUNCTION_DEVIATION             = _UxGT("Desv. Juncao");
  LSTR MSG_MAX_SPEED                      = _UxGT("Velocidade (mm/s)");
  LSTR MSG_VMAX_A                         = _UxGT("Max ") STR_A _UxGT(" Velocidade");
  LSTR MSG_VMAX_B                         = _UxGT("Max ") STR_B _UxGT(" Velocidade");
  LSTR MSG_VMAX_C                         = _UxGT("Max ") STR_C _UxGT(" Velocidade");
  LSTR MSG_VMAX_N                         = _UxGT("Max @ Velocidade");
  LSTR MSG_VMAX_E                         = _UxGT("Max E Velocidade");
  LSTR MSG_VMAX_EN                        = _UxGT("Max * Velocidade");
  LSTR MSG_VMIN                           = _UxGT("Min Velocidade");
  LSTR MSG_VTRAV_MIN                      = _UxGT("VDeslocamento min");
  LSTR MSG_ACCELERATION                   = _UxGT("Aceleracao");
  LSTR MSG_AMAX_A                         = _UxGT("Max ") STR_A _UxGT(" Accel");
  LSTR MSG_AMAX_B                         = _UxGT("Max ") STR_B _UxGT(" Accel");
  LSTR MSG_AMAX_C                         = _UxGT("Max ") STR_C _UxGT(" Accel");
  LSTR MSG_AMAX_N                         = _UxGT("Max @ Accel");
  LSTR MSG_AMAX_E                         = _UxGT("Max E Accel");
  LSTR MSG_AMAX_EN                        = _UxGT("Max * Accel");
  LSTR MSG_A_RETRACT                      = _UxGT("Retrair A");
  LSTR MSG_A_TRAVEL                       = _UxGT("Movimento A");
  LSTR MSG_XY_FREQUENCY_LIMIT             = _UxGT("XY Freq Limit");
  LSTR MSG_XY_FREQUENCY_FEEDRATE          = _UxGT("Min FR Factor");
  LSTR MSG_STEPS_PER_MM                   = _UxGT("Passo/mm");
  LSTR MSG_A_STEPS                        = STR_A _UxGT(" Passo/mm");
  LSTR MSG_B_STEPS                        = STR_B _UxGT(" Passo/mm");
  LSTR MSG_C_STEPS                        = STR_C _UxGT(" Passo/mm");
  LSTR MSG_N_STEPS                        = _UxGT("@ passo/mm");
  LSTR MSG_E_STEPS                        = _UxGT("E passo/mm");
  LSTR MSG_EN_STEPS                       = _UxGT("* passo/mm");
  LSTR MSG_TEMPERATURE                    = _UxGT("Temperatura");
  LSTR MSG_MOTION                         = _UxGT("Movimento");
  LSTR MSG_FILAMENT                       = _UxGT("Filamento");
  LSTR MSG_VOLUMETRIC_ENABLED             = _UxGT("E em mm") SUPERSCRIPT_THREE;
  LSTR MSG_VOLUMETRIC_LIMIT               = _UxGT("E Limite em mm") SUPERSCRIPT_THREE;
  LSTR MSG_VOLUMETRIC_LIMIT_E             = _UxGT("E Limite *");
  LSTR MSG_FILAMENT_DIAM                  = _UxGT("Diametro Fil.");
  LSTR MSG_FILAMENT_DIAM_E                = _UxGT("Diametro Fil. *");
  LSTR MSG_FILAMENT_UNLOAD                = _UxGT("Descarr mm");
  LSTR MSG_FILAMENT_LOAD                  = _UxGT("Carregar mm");
  LSTR MSG_ADVANCE_K                      = _UxGT("Avanco K");
  LSTR MSG_ADVANCE_K_E                    = _UxGT("Avanco K *");
  LSTR MSG_CONTRAST                       = _UxGT("Contraste");
  LSTR MSG_BRIGHTNESS                     = _UxGT("Brilho");
  LSTR MSG_LCD_TIMEOUT_SEC                = _UxGT("LCD Timeout (s)");
  LSTR MSG_SCREEN_TIMEOUT                 = _UxGT("LCD Timeout (m)");
  LSTR MSG_BRIGHTNESS_OFF                 = _UxGT("Desligar LCD");
  LSTR MSG_STORE_EEPROM                   = _UxGT("Salvar Configuracao");
  LSTR MSG_LOAD_EEPROM                    = _UxGT("Ler Configuracao");
  LSTR MSG_RESTORE_DEFAULTS               = _UxGT("Restaurar padrao");
  LSTR MSG_INIT_EEPROM                    = _UxGT("Inicializar EEPROM");
  LSTR MSG_ERR_EEPROM_CRC                 = _UxGT("Erro CRC EEPROM");
  LSTR MSG_ERR_EEPROM_INDEX               = _UxGT("Erro indice EEPROM");
  LSTR MSG_ERR_EEPROM_VERSION             = _UxGT("Erro versao EEPROM");
  LSTR MSG_SETTINGS_STORED                = _UxGT("Config. gravada");
  LSTR MSG_MEDIA_UPDATE                   = _UxGT("Cartao SD atualizado");
  LSTR MSG_RESET_PRINTER                  = _UxGT("Reiniciar impressora");
  LSTR MSG_REFRESH                        = LCD_STR_REFRESH _UxGT("Atualizacao");
  LSTR MSG_INFO_SCREEN                    = _UxGT("Informacoes");
  LSTR MSG_INFO_MACHINENAME               = _UxGT("Nome maquina");
  LSTR MSG_INFO_SIZE                      = _UxGT("Tamanho");
  LSTR MSG_INFO_FWVERSION                 = _UxGT("Versao Firmware");
  LSTR MSG_INFO_BUILD                     = _UxGT("Compilado em");
  LSTR MSG_PREPARE                        = _UxGT("Preparar");
  LSTR MSG_TUNE                           = _UxGT("Ajustar");
  LSTR MSG_POWER_MONITOR                  = _UxGT("Monitor potencia");
  LSTR MSG_CURRENT                        = _UxGT("Corrente");
  LSTR MSG_VOLTAGE                        = _UxGT("Tensao");
  LSTR MSG_POWER                          = _UxGT("Potencia");
  LSTR MSG_START_PRINT                    = _UxGT("Iniciar impressao");
  LSTR MSG_BUTTON_NEXT                    = _UxGT("Prox.");
  LSTR MSG_BUTTON_INIT                    = _UxGT("Iniciar");
  LSTR MSG_BUTTON_STOP                    = _UxGT("Parar");
  LSTR MSG_BUTTON_PRINT                   = _UxGT("Imprimir");
  LSTR MSG_BUTTON_RESET                   = _UxGT("Resetar");
  LSTR MSG_BUTTON_IGNORE                  = _UxGT("Ignorar");
  LSTR MSG_BUTTON_CANCEL                  = _UxGT("Cancelar");
  LSTR MSG_BUTTON_CONFIRM                 = _UxGT("Confirmar");
  LSTR MSG_BUTTON_CONTINUE                = _UxGT("Continuar");
  LSTR MSG_BUTTON_DONE                    = _UxGT("Pronto");
  LSTR MSG_BUTTON_BACK                    = _UxGT("Voltar");
  LSTR MSG_BUTTON_PROCEED                 = _UxGT("Continuar");
  LSTR MSG_BUTTON_SKIP                    = _UxGT("Pular");
  LSTR MSG_BUTTON_INFO                    = _UxGT("Info");
  LSTR MSG_BUTTON_LEVEL                   = _UxGT("Nivel");
  LSTR MSG_BUTTON_PAUSE                   = _UxGT("Pausar");
  LSTR MSG_BUTTON_RESUME                  = _UxGT("Resume");
  LSTR MSG_BUTTON_ADVANCED                = _UxGT("Avancado");
  LSTR MSG_BUTTON_SAVE                    = _UxGT("Salvar");
  LSTR MSG_BUTTON_PURGE                   = _UxGT("Purgar");
  LSTR MSG_PAUSING                        = _UxGT("Pausando...");
  LSTR MSG_PAUSE_PRINT                    = _UxGT("Pausar impressao");
  LSTR MSG_ADVANCED_PAUSE                 = _UxGT("Pausa avancada");
  LSTR MSG_RESUME_PRINT                   = _UxGT("Resume impressao");
  LSTR MSG_HOST_START_PRINT               = _UxGT("Iniciar Impressao");
  LSTR MSG_STOP_PRINT                     = _UxGT("Parar impressao");
  LSTR MSG_END_LOOPS                      = _UxGT("Fim repeticao");
  LSTR MSG_PRINTING_OBJECT                = _UxGT("Imprimindo objeto");
  LSTR MSG_CANCEL_OBJECT                  = _UxGT("Cancelar Objeto");
  LSTR MSG_CANCEL_OBJECT_N                = _UxGT("Cancelar Objeto =");
  LSTR MSG_OUTAGE_RECOVERY                = _UxGT("Recuperar Impressao");
  LSTR MSG_CONTINUE_PRINT_JOB             = _UxGT("Continuar fila de impressao");
  LSTR MSG_MEDIA_MENU                     = _UxGT("Imprimir do SD");
  LSTR MSG_NO_MEDIA                       = _UxGT("Sem cartao SD");
  LSTR MSG_DWELL                          = _UxGT("Dormindo...");
  LSTR MSG_USERWAIT                       = _UxGT("Clique para retomar...");
  LSTR MSG_PRINT_PAUSED                   = _UxGT("Impressao Pausada");
  LSTR MSG_PRINTING                       = _UxGT("Imprimindo...");
  LSTR MSG_STOPPING                       = _UxGT("Parando...");
  LSTR MSG_REMAINING_TIME                 = _UxGT("Restante");
  LSTR MSG_PRINT_ABORTED                  = _UxGT("Impressao Abortada");
  LSTR MSG_PRINT_DONE                     = _UxGT("Impressao pronta");
  LSTR MSG_PRINTER_KILLED                 = _UxGT("Impressora morta!");
  LSTR MSG_TURN_OFF                       = _UxGT("Desligue a impressora");
  LSTR MSG_NO_MOVE                        = _UxGT("Sem movimento.");
  LSTR MSG_KILLED                         = _UxGT("PARADA DE EMERGENCIA. ");
  LSTR MSG_STOPPED                        = _UxGT("PAROU. ");
  LSTR MSG_FWRETRACT                      = _UxGT("Retrair Firmware");
  LSTR MSG_CONTROL_RETRACT                = _UxGT("Retrair mm");
  LSTR MSG_CONTROL_RETRACT_SWAP           = _UxGT("Retrair Troca mm");
  LSTR MSG_CONTROL_RETRACTF               = _UxGT("Retrair V");
  LSTR MSG_CONTROL_RETRACT_ZHOP           = _UxGT("Saltar mm");
  LSTR MSG_CONTROL_RETRACT_RECOVER        = _UxGT("Des-retrair");
  LSTR MSG_CONTROL_RETRACT_RECOVER_SWAP   = _UxGT("Des-RetTroca mm");
  LSTR MSG_CONTROL_RETRACT_RECOVERF       = _UxGT("Des-Retrair V");
  LSTR MSG_CONTROL_RETRACT_RECOVER_SWAPF  = _UxGT("Des-RetTroca V");
  LSTR MSG_AUTORETRACT                    = _UxGT("Retracao Automatica");
  LSTR MSG_FILAMENT_SWAP_LENGTH           = _UxGT("Distancia Retracao");
  LSTR MSG_FILAMENT_SWAP_EXTRA            = _UxGT("Troca extra");
  LSTR MSG_FILAMENT_PURGE_LENGTH          = _UxGT("Distancia purga");
  LSTR MSG_TOOL_CHANGE                    = _UxGT("Mudar Ferramenta");
  LSTR MSG_TOOL_CHANGE_ZLIFT              = _UxGT("Levantar Z");
  LSTR MSG_SINGLENOZZLE_PRIME_SPEED       = _UxGT("Preparar Veloc.");
  LSTR MSG_SINGLENOZZLE_RETRACT_SPEED     = _UxGT("Veloc. Retracao");
  LSTR MSG_FILAMENT_PARK_ENABLED          = _UxGT("Posicionar");
  LSTR MSG_PARK_XPOSITION                 = _UxGT("Posicao descanso X");
  LSTR MSG_PARK_YPOSITION                 = _UxGT("Posicao descanso Y");
  LSTR MSG_PARK_ZRAISE                    = _UxGT("Elevacao Z");
  LSTR MSG_PHY_SET                        = _UxGT("Config. fisicas");
  LSTR MSG_PHY_XBEDSIZE                   = _UxGT("Tamanho X mesa");
  LSTR MSG_PHY_YBEDSIZE                   = _UxGT("Tamanho Y mesa");
  LSTR MSG_PHY_XMINPOS                    = _UxGT("Posicao X min");
  LSTR MSG_PHY_YMINPOS                    = _UxGT("Posicao Y min");
  LSTR MSG_PHY_XMAXPOS                    = _UxGT("Posicao X max");
  LSTR MSG_PHY_YMAXPOS                    = _UxGT("Posicao Y max");
  LSTR MSG_PHY_ZMAXPOS                    = _UxGT("Posicao Z max");
  LSTR MSG_SINGLENOZZLE_UNRETRACT_SPEED   = _UxGT("Recuperar velocidade");
  LSTR MSG_SINGLENOZZLE_FAN_SPEED         = _UxGT("Velocidade Fan");
  LSTR MSG_SINGLENOZZLE_FAN_TIME          = _UxGT("Tempo Fan");
  LSTR MSG_TOOL_MIGRATION_ON              = _UxGT("Auto LIGAR");
  LSTR MSG_TOOL_MIGRATION_OFF             = _UxGT("Auto DESL.");
  LSTR MSG_TOOL_MIGRATION                 = _UxGT("Ferramenta migracao");
  LSTR MSG_TOOL_MIGRATION_AUTO            = _UxGT("Auto-migracao");
  LSTR MSG_TOOL_MIGRATION_END             = _UxGT("Ultima Extrusora");
  LSTR MSG_TOOL_MIGRATION_SWAP            = _UxGT("Migrar para *");
  LSTR MSG_FILAMENTCHANGE                 = _UxGT("Trocar filamento");
  LSTR MSG_FILAMENTCHANGE_E               = _UxGT("Trocar filamento *");
  LSTR MSG_FILAMENTLOAD                   = _UxGT("Carregar filamento");
  LSTR MSG_FILAMENTLOAD_E                 = _UxGT("Carregar *");
  LSTR MSG_FILAMENTUNLOAD                 = _UxGT("Descarreg. Filamento");
  LSTR MSG_FILAMENTUNLOAD_E               = _UxGT("Descarregar *");
  LSTR MSG_FILAMENTUNLOAD_ALL             = _UxGT("Descarregar TUDO");
  LSTR MSG_ATTACH_MEDIA                   = _UxGT("Iniciar SD");
  LSTR MSG_CHANGE_MEDIA                   = _UxGT("Trocar SD");
  LSTR MSG_RELEASE_MEDIA                  = _UxGT("Liberar SD ");
  LSTR MSG_ZPROBE_OUT                     = _UxGT("Sensor fora/base");
  LSTR MSG_SKEW_FACTOR                    = _UxGT("Fator de inclinacao");
  LSTR MSG_BLTOUCH                        = _UxGT("BLTouch");
  LSTR MSG_BLTOUCH_SELFTEST               = _UxGT("Auto-teste");
  LSTR MSG_BLTOUCH_RESET                  = _UxGT("Resetar");
  LSTR MSG_BLTOUCH_STOW                   = _UxGT("Recolher");
  LSTR MSG_BLTOUCH_DEPLOY                 = _UxGT("Estender");
  LSTR MSG_BLTOUCH_SW_MODE                = _UxGT("Modo-SW");
  LSTR MSG_BLTOUCH_SPEED_MODE             = _UxGT("Alta velocidade");
  LSTR MSG_BLTOUCH_5V_MODE                = _UxGT("Modo-5V");
  LSTR MSG_BLTOUCH_OD_MODE                = _UxGT("Modo-OD");
  LSTR MSG_BLTOUCH_MODE_STORE             = _UxGT("Modo-gravar");
  LSTR MSG_BLTOUCH_MODE_STORE_5V          = _UxGT("Config. BLTouch para 5V");
  LSTR MSG_BLTOUCH_MODE_STORE_OD          = _UxGT("Config. BLTouch para OD");
  LSTR MSG_BLTOUCH_MODE_ECHO              = _UxGT("Reportar dreno");
  LSTR MSG_BLTOUCH_MODE_CHANGE            = _UxGT("PERIGO: Config. errada pode causar problemas! Confirma?");
  LSTR MSG_TOUCHMI_PROBE                  = _UxGT("TouchMI");
  LSTR MSG_TOUCHMI_INIT                   = _UxGT("Inicia TouchMI");
  LSTR MSG_TOUCHMI_ZTEST                  = _UxGT("Teste desloc. Z");
  LSTR MSG_TOUCHMI_SAVE                   = _UxGT("Salvar");
  LSTR MSG_MANUAL_DEPLOY_TOUCHMI          = _UxGT("Implantar TouchMI");
  LSTR MSG_MANUAL_DEPLOY                  = _UxGT("Implantar Z-Probe");
  LSTR MSG_MANUAL_STOW                    = _UxGT("Recolher Z-Probe");
  LSTR MSG_HOME_FIRST                     = _UxGT("Origem %s%s%s Primeiro");
  LSTR MSG_ZPROBE_SETTINGS                = _UxGT("Config. sonda");
  LSTR MSG_ZPROBE_OFFSETS                 = _UxGT("Compensar sonda");
  LSTR MSG_ZPROBE_XOFFSET                 = _UxGT("Comp. Sonda em X");
  LSTR MSG_ZPROBE_YOFFSET                 = _UxGT("Comp. Sonda em Y");
  LSTR MSG_ZPROBE_ZOFFSET                 = _UxGT("Comp. Sonda em Z");
  LSTR MSG_ZPROBE_MARGIN                  = _UxGT("Sondar margem");
  LSTR MSG_ZPROBE_MULTIPLE                = _UxGT("Multiplas sondas");
  LSTR MSG_Z_FEED_RATE                    = _UxGT("Taxa Z");
  LSTR MSG_ENABLE_HS_MODE                 = _UxGT("Ativar modo HS");
  LSTR MSG_MOVE_NOZZLE_TO_BED             = _UxGT("Move Bico para mesa");
  LSTR MSG_BABYSTEP_X                     = _UxGT("Passinho X");
  LSTR MSG_BABYSTEP_Y                     = _UxGT("Passinho Y");
  LSTR MSG_BABYSTEP_Z                     = _UxGT("Passinho Z");
  LSTR MSG_BABYSTEP_N                     = _UxGT("Passinho @");
  LSTR MSG_BABYSTEP_TOTAL                 = _UxGT("Total");
  LSTR MSG_ENDSTOP_ABORT                  = _UxGT("Abortar Fim de Curso");
  LSTR MSG_HEATING_FAILED_LCD             = _UxGT("Aquecimento falhou");
  LSTR MSG_ERR_REDUNDANT_TEMP             = _UxGT("Erro:Temp Redundante");
  LSTR MSG_THERMAL_RUNAWAY                = _UxGT("ESCAPE TERMICO");
  LSTR MSG_TEMP_MALFUNCTION               = _UxGT("MAU FUNCIONAMENTO TEMP");
  LSTR MSG_THERMAL_RUNAWAY_BED            = _UxGT("ESCAPE TERMICO MESA");
  LSTR MSG_THERMAL_RUNAWAY_CHAMBER        = _UxGT("ESCAPE TERMICO CAMARA");
  LSTR MSG_THERMAL_RUNAWAY_COOLER         = _UxGT("Escape cooler");
  LSTR MSG_COOLING_FAILED                 = _UxGT("Falha resfriamento");
  LSTR MSG_ERR_MAXTEMP                    = _UxGT("Err: T Maxima");
  LSTR MSG_ERR_MINTEMP                    = _UxGT("Err: T Minima");
  LSTR MSG_HALTED                         = _UxGT("IMPRESSORA TRAVADA");
  LSTR MSG_PLEASE_WAIT                    = _UxGT("Favor aguarde...");
  LSTR MSG_PLEASE_RESET                   = _UxGT("Favor Resetar");
  LSTR MSG_PREHEATING                     = _UxGT("Pre-aquecendo...");
  LSTR MSG_HEATING                        = _UxGT("Aquecendo...");
  LSTR MSG_COOLING                        = _UxGT("Esfriando...");
  LSTR MSG_BED_HEATING                    = _UxGT("Aquecendo Base...");
  LSTR MSG_BED_COOLING                    = _UxGT("Esfriando Base...");
  LSTR MSG_PROBE_HEATING                  = _UxGT("Aquecimento da sonda...");
  LSTR MSG_PROBE_COOLING                  = _UxGT("Sonda esfriando...");
  LSTR MSG_CHAMBER_HEATING                = _UxGT("Camara aquecendo...");
  LSTR MSG_CHAMBER_COOLING                = _UxGT("Camara esfriando...");
  LSTR MSG_LASER_COOLING                  = _UxGT("Laser esfriando...");
  LSTR MSG_DELTA_CALIBRATE                = _UxGT("Calibrar Delta");
  LSTR MSG_DELTA_CALIBRATE_X              = _UxGT("Calibrar X");
  LSTR MSG_DELTA_CALIBRATE_Y              = _UxGT("Calibrar Y");
  LSTR MSG_DELTA_CALIBRATE_Z              = _UxGT("Calibrar Z");
  LSTR MSG_DELTA_CALIBRATE_CENTER         = _UxGT("Calibrar Centro");
  LSTR MSG_DELTA_SETTINGS                 = _UxGT("Configuracao Delta");
  LSTR MSG_DELTA_AUTO_CALIBRATE           = _UxGT("Auto-Calibracao");
  LSTR MSG_DELTA_DIAG_ROD                 = _UxGT("Haste Diagonal");
  LSTR MSG_DELTA_HEIGHT                   = _UxGT("Altura");
  LSTR MSG_DELTA_RADIUS                   = _UxGT("Raio");
  LSTR MSG_INFO_MENU                      = _UxGT("Sobre");
  LSTR MSG_INFO_PRINTER_MENU              = _UxGT("Impressora");
  LSTR MSG_3POINT_LEVELING                = _UxGT("Nivelamento 3 pontos");
  LSTR MSG_LINEAR_LEVELING                = _UxGT("Nivelamento Linear");
  LSTR MSG_BILINEAR_LEVELING              = _UxGT("Nivelamento Bilinear");
  LSTR MSG_UBL_LEVELING                   = _UxGT("Nivelamento UBL");
  LSTR MSG_MESH_LEVELING                  = _UxGT("Nivelamento da Malha");
  LSTR MSG_MESH_DONE                      = _UxGT("Sondagem malha pronta");
  LSTR MSG_MESH_POINTS                    = _UxGT("Pontos de malha");
  LSTR MSG_INFO_STATS_MENU                = _UxGT("Estatisticas");
  LSTR MSG_INFO_BOARD_MENU                = _UxGT("Info. da Placa");
  LSTR MSG_INFO_THERMISTOR_MENU           = _UxGT("Termistores");
  LSTR MSG_INFO_EXTRUDERS                 = _UxGT("Extrusoras");
  LSTR MSG_INFO_BAUDRATE                  = _UxGT("Taxa de Transmissao");
  LSTR MSG_INFO_PROTOCOL                  = _UxGT("Protocolo");
  LSTR MSG_INFO_RUNAWAY_OFF               = _UxGT("Relogio fuga: DESL.");
  LSTR MSG_INFO_RUNAWAY_ON                = _UxGT("Relogio fuga: LIG");
  LSTR MSG_HOTEND_IDLE_TIMEOUT            = _UxGT("Limite inatividade Hotend");
  LSTR MSG_FAN_SPEED_FAULT                = _UxGT("Falha Velocidade Fan");

  LSTR MSG_CASE_LIGHT                     = _UxGT("Luz da Impressora");
  LSTR MSG_CASE_LIGHT_BRIGHTNESS          = _UxGT("Intensidade Brilho");
  LSTR MSG_KILL_EXPECTED_PRINTER          = _UxGT("IMPRESSORA INCORRETA");

  LSTR MSG_COLORS_GET                     = _UxGT("Obter cor");
  LSTR MSG_COLORS_SELECT                  = _UxGT("Selecionar cor");
  LSTR MSG_COLORS_APPLIED                 = _UxGT("Aplicar cor");
  LSTR MSG_COLORS_RED                     = _UxGT("Vermelho");
  LSTR MSG_COLORS_GREEN                   = _UxGT("Verde");
  LSTR MSG_COLORS_BLUE                    = _UxGT("Azul");
  LSTR MSG_COLORS_WHITE                   = _UxGT("Branco");
  LSTR MSG_UI_LANGUAGE                    = _UxGT("Idioma UI");
  LSTR MSG_SOUND_ENABLE                   = _UxGT("Ativar som");
  LSTR MSG_LOCKSCREEN                     = _UxGT("Bloquear tela");
  LSTR MSG_LOCKSCREEN_LOCKED              = _UxGT("Impressora bloqueada,");
  LSTR MSG_LOCKSCREEN_UNLOCK              = _UxGT("Girar para desbloquear.");
  LSTR MSG_PLEASE_WAIT_REBOOT             = _UxGT("Iniciando... Aguarde.");

  #if LCD_WIDTH >= 20 || HAS_DWIN_E3V2
    LSTR MSG_MEDIA_NOT_INSERTED           = _UxGT("Nenhum cartao inserido.");
    LSTR MSG_PLEASE_PREHEAT               = _UxGT("Favor pre-aquecer o hotend.");
    LSTR MSG_INFO_PRINT_COUNT_RESET       = _UxGT("Resetar contador");
    LSTR MSG_INFO_PRINT_COUNT             = _UxGT("Contador");
    LSTR MSG_INFO_PRINT_TIME              = _UxGT("Duracao");
    LSTR MSG_INFO_PRINT_LONGEST           = _UxGT("Trabalho mais longo");
    LSTR MSG_INFO_PRINT_FILAMENT          = _UxGT("Total de Extrusao");
  #else
    LSTR MSG_MEDIA_NOT_INSERTED           = _UxGT("sem cartao");
    LSTR MSG_PLEASE_PREHEAT               = _UxGT("Favor pre-aquecer");
    LSTR MSG_INFO_PRINT_COUNT             = _UxGT("Impressoes");
    LSTR MSG_INFO_PRINT_TIME              = _UxGT("Total");
    LSTR MSG_INFO_PRINT_LONGEST           = _UxGT("Maior trabalho");
    LSTR MSG_INFO_PRINT_FILAMENT          = _UxGT("T. Extrusao");
  #endif

  LSTR MSG_INFO_COMPLETED_PRINTS          = _UxGT("Completo");
  LSTR MSG_INFO_MIN_TEMP                  = _UxGT("Temp. Min");
  LSTR MSG_INFO_MAX_TEMP                  = _UxGT("Temp. Max");
  LSTR MSG_INFO_PSU                       = _UxGT("PSU");
  LSTR MSG_DRIVE_STRENGTH                 = _UxGT("Forca do Motor");
  LSTR MSG_DAC_PERCENT_N                  = _UxGT("@ Driver %");
  LSTR MSG_ERROR_TMC                      = _UxGT("ERRO DE CONEXAO TMC");
  LSTR MSG_DAC_EEPROM_WRITE               = _UxGT("Escrever Eeprom DAC");
  LSTR MSG_FILAMENT_CHANGE_HEADER         = _UxGT("Troca de Filamento");
  LSTR MSG_FILAMENT_CHANGE_HEADER_PAUSE   = _UxGT("IMPRESSORA PAUSADA");
  LSTR MSG_FILAMENT_CHANGE_HEADER_LOAD    = _UxGT("CARREGAR FILAMENTO");
  LSTR MSG_FILAMENT_CHANGE_HEADER_UNLOAD  = _UxGT("REMOVER FILAMENTO");
  LSTR MSG_FILAMENT_CHANGE_OPTION_HEADER  = _UxGT("CONFIG. DE RETOMADA:");
  LSTR MSG_FILAMENT_CHANGE_OPTION_PURGE   = _UxGT("Extrusar Mais");
  LSTR MSG_FILAMENT_CHANGE_OPTION_RESUME  = _UxGT("Continuar Impressao");
  LSTR MSG_FILAMENT_CHANGE_PURGE_CONTINUE = _UxGT("Purgar ou Continuar?");
  LSTR MSG_FILAMENT_CHANGE_NOZZLE         = _UxGT("  Bico: ");
  LSTR MSG_RUNOUT_SENSOR                  = _UxGT("Sensor de Excentricidade");
  LSTR MSG_RUNOUT_DISTANCE_MM             = _UxGT("Dist. de saida mm");
  LSTR MSG_RUNOUT_ENABLE                  = _UxGT("Ativar excentricidade");
  LSTR MSG_RUNOUT_ACTIVE                  = _UxGT("Esgotamento Ativo");
  LSTR MSG_INVERT_EXTRUDER                = _UxGT("Extrusora Invertida");
  LSTR MSG_EXTRUDER_MIN_TEMP              = _UxGT("Extrusor Min Temp.");
  LSTR MSG_FANCHECK                       = _UxGT("Verificacao do taco do ventilador");
  LSTR MSG_KILL_HOMING_FAILED             = _UxGT("Falha no posicionamento");
  LSTR MSG_LCD_PROBING_FAILED             = _UxGT("Falha ao sondar");

  LSTR MSG_MMU2_CHOOSE_FILAMENT_HEADER    = _UxGT("ESCOLHER FILAMENTO");
  LSTR MSG_MMU2_MENU                      = _UxGT("MMU");
  LSTR MSG_KILL_MMU2_FIRMWARE             = _UxGT("Atualizar firmware MMU!");
  LSTR MSG_MMU2_NOT_RESPONDING            = _UxGT("MMU precisa atencao.");
  LSTR MSG_MMU2_RESUME                    = _UxGT("MMU Resumida");
  LSTR MSG_MMU2_RESUMING                  = _UxGT("MMU Resumindo...");
  LSTR MSG_MMU2_LOAD_FILAMENT             = _UxGT("MMU Carregada");
  LSTR MSG_MMU2_LOAD_ALL                  = _UxGT("MMU Carregada toda");
  LSTR MSG_MMU2_LOAD_TO_NOZZLE            = _UxGT("MMU Carregada para bico");
  LSTR MSG_MMU2_EJECT_FILAMENT            = _UxGT("Ejetar MMU");
  LSTR MSG_MMU2_EJECT_FILAMENT_N          = _UxGT("Ejetar MMU ~");
  LSTR MSG_MMU2_UNLOAD_FILAMENT           = _UxGT("Descarregar MMU");
  LSTR MSG_MMU2_LOADING_FILAMENT          = _UxGT("Carregando Fil. %i...");
  LSTR MSG_MMU2_EJECTING_FILAMENT         = _UxGT("Ejetando Fil. ...");
  LSTR MSG_MMU2_UNLOADING_FILAMENT        = _UxGT("Removendo Fil....");
  LSTR MSG_MMU2_ALL                       = _UxGT("Tudo");
  LSTR MSG_MMU2_FILAMENT_N                = _UxGT("Filamento ~");
  LSTR MSG_MMU2_RESET                     = _UxGT("Resetar MMU");
  LSTR MSG_MMU2_RESETTING                 = _UxGT("Resetando MMU...");
  LSTR MSG_MMU2_EJECT_RECOVER             = _UxGT("Remover, click");

  LSTR MSG_MIX                            = _UxGT("Mix");
  LSTR MSG_MIX_COMPONENT_N                = _UxGT("Componente =");
  LSTR MSG_MIXER                          = _UxGT("Misturador");
  LSTR MSG_GRADIENT                       = _UxGT("Gradiente");
  LSTR MSG_FULL_GRADIENT                  = _UxGT("Gradiente Total");
  LSTR MSG_TOGGLE_MIX                     = _UxGT("Alternar Mistura");
  LSTR MSG_CYCLE_MIX                      = _UxGT("Mistura de ciclos");
  LSTR MSG_GRADIENT_MIX                   = _UxGT("Mistura Gradiente");
  LSTR MSG_REVERSE_GRADIENT               = _UxGT("Gradiente reverso");
  LSTR MSG_ACTIVE_VTOOL                   = _UxGT("Ferramenta V ativa");
  LSTR MSG_START_VTOOL                    = _UxGT("Iniciar ferramenta V");
  LSTR MSG_END_VTOOL                      = _UxGT("  Fim ferramenta V");
  LSTR MSG_GRADIENT_ALIAS                 = _UxGT("Alias ​​ferramenta V");
  LSTR MSG_RESET_VTOOLS                   = _UxGT("Redefinir ferramentas V");
  LSTR MSG_COMMIT_VTOOL                   = _UxGT("Commit V-tool Mix");
  LSTR MSG_VTOOLS_RESET                   = _UxGT("Ferramentas V redefinidas");
  LSTR MSG_START_Z                        = _UxGT("Iniciar Z:");
  LSTR MSG_END_Z                          = _UxGT("  Fim Z:");

  LSTR MSG_GAMES                          = _UxGT("Jogos");
  LSTR MSG_BRICKOUT                       = _UxGT("Brickout");
  LSTR MSG_INVADERS                       = _UxGT("Invasores");
  LSTR MSG_SNAKE                          = _UxGT("Sn4k3");
  LSTR MSG_MAZE                           = _UxGT("Labirinto");

  LSTR MSG_BAD_PAGE                       = _UxGT("Indice de pagina errado");
  LSTR MSG_BAD_PAGE_SPEED                 = _UxGT("Velocidade de pagina errado");

  LSTR MSG_EDIT_PASSWORD                  = _UxGT("Editar senha");
  LSTR MSG_LOGIN_REQUIRED                 = _UxGT("Login obrigatorio");
  LSTR MSG_PASSWORD_SETTINGS              = _UxGT("Config. Senha");
  LSTR MSG_ENTER_DIGIT                    = _UxGT("Digite o digito");
  LSTR MSG_CHANGE_PASSWORD                = _UxGT("Definir/editar senha");
  LSTR MSG_REMOVE_PASSWORD                = _UxGT("Remove Password");
  LSTR MSG_PASSWORD_SET                   = _UxGT("A senha e ");
  LSTR MSG_START_OVER                     = _UxGT("Recomecar");
  LSTR MSG_REMINDER_SAVE_SETTINGS         = _UxGT("Lembre-se de Salvar!");
  LSTR MSG_PASSWORD_REMOVED               = _UxGT("Senha removida");

  //
  // Filament Change screens show up to 3 lines on a 4-line display
  //                        ...or up to 2 lines on a 3-line display
  //
  #if LCD_HEIGHT >= 4
    LSTR MSG_ADVANCED_PAUSE_WAITING       = _UxGT(MSG_2_LINE("Press. Botao", "para resumir impressao"));
    LSTR MSG_PAUSE_PRINT_PARKING          = _UxGT(MSG_1_LINE("Posicionando..."));
    LSTR MSG_FILAMENT_CHANGE_INIT         = _UxGT(MSG_3_LINE("Aguarde pela", "troca de filamento", "para iniciar"));
    LSTR MSG_FILAMENT_CHANGE_INSERT       = _UxGT(MSG_3_LINE("Insira filamento", "e pressione o botao", "para continuar"));
    LSTR MSG_FILAMENT_CHANGE_HEAT         = _UxGT(MSG_2_LINE("Pressione o botao", "para aquecer o bico"));
    LSTR MSG_FILAMENT_CHANGE_HEATING      = _UxGT(MSG_2_LINE("Bico aquecendo", "Favor aguardar..."));
    LSTR MSG_FILAMENT_CHANGE_UNLOAD       = _UxGT(MSG_2_LINE("Aguardando a", "carga de filamento"));
    LSTR MSG_FILAMENT_CHANGE_LOAD         = _UxGT(MSG_2_LINE("Aguardando a", "carga de filamento"));
    LSTR MSG_FILAMENT_CHANGE_PURGE        = _UxGT(MSG_2_LINE("Aguardando a", "purga de filamento"));
    LSTR MSG_FILAMENT_CHANGE_CONT_PURGE   = _UxGT(MSG_2_LINE("Clique para finalizar", "purga de filamento"));
    LSTR MSG_FILAMENT_CHANGE_RESUME       = _UxGT(MSG_2_LINE("Aguarde a impressao", "retomar..."));
  #else
    LSTR MSG_ADVANCED_PAUSE_WAITING       = _UxGT(MSG_1_LINE("Clique para continuar"));
    LSTR MSG_PAUSE_PRINT_PARKING          = _UxGT(MSG_1_LINE("Posicionando..."));
    LSTR MSG_FILAMENT_CHANGE_INIT         = _UxGT(MSG_1_LINE("Por favor, espere..."));
    LSTR MSG_FILAMENT_CHANGE_INSERT       = _UxGT(MSG_1_LINE("Insira e clique"));
    LSTR MSG_FILAMENT_CHANGE_HEAT         = _UxGT(MSG_1_LINE("Clique para aquecer"));
    LSTR MSG_FILAMENT_CHANGE_HEATING      = _UxGT(MSG_1_LINE("Aquecendo..."));
    LSTR MSG_FILAMENT_CHANGE_UNLOAD       = _UxGT(MSG_1_LINE("Ejetando..."));
    LSTR MSG_FILAMENT_CHANGE_LOAD         = _UxGT(MSG_1_LINE("Carregando..."));
    LSTR MSG_FILAMENT_CHANGE_PURGE        = _UxGT(MSG_1_LINE("Purgando..."));
    LSTR MSG_FILAMENT_CHANGE_CONT_PURGE   = _UxGT(MSG_1_LINE("Clique para finalizar"));
    LSTR MSG_FILAMENT_CHANGE_RESUME       = _UxGT(MSG_1_LINE("Retomar..."));
  #endif
  LSTR MSG_TMC_DRIVERS                    = _UxGT("Drivers TMC");
  LSTR MSG_TMC_CURRENT                    = _UxGT("Corrente do Driver");
  LSTR MSG_TMC_HYBRID_THRS                = _UxGT("Limite Hibrido");
  LSTR MSG_TMC_HOMING_THRS                = _UxGT("Retorno sem sensor");
  LSTR MSG_TMC_STEPPING_MODE              = _UxGT("Modo de passo");
  LSTR MSG_TMC_STEALTH_ENABLED            = _UxGT("StealthChop ativado");
  LSTR MSG_SERVICE_RESET                  = _UxGT("Resetar");
  LSTR MSG_SERVICE_IN                     = _UxGT(" in:");
  LSTR MSG_BACKLASH                       = _UxGT("Retaliacao");
  LSTR MSG_BACKLASH_CORRECTION            = _UxGT("Correcao");
  LSTR MSG_BACKLASH_SMOOTHING             = _UxGT("Suavizacao");

  LSTR MSG_LEVEL_X_AXIS                   = _UxGT("Nivel eixo X");
  LSTR MSG_AUTO_CALIBRATE                 = _UxGT("Auto Calibrar");
  #if ENABLED(TOUCH_UI_FTDI_EVE)
    LSTR MSG_HEATER_TIMEOUT               = _UxGT("Tempo limite de inatividade, temperatura reduzida. Pressione OK para reaquecer e novamente para retomar.");
  #else
    LSTR MSG_HEATER_TIMEOUT               = _UxGT("Tempo limite do aquecedor");
  #endif
  LSTR MSG_REHEAT                         = _UxGT("Reaquecer");
  LSTR MSG_REHEATING                      = _UxGT("Reaquecendo...");
  LSTR MSG_REHEATDONE                     = _UxGT("Reaquecimento concluido");

  LSTR MSG_PROBE_WIZARD                   = _UxGT("Assistente de sonda Z");
  LSTR MSG_PROBE_WIZARD_PROBING           = _UxGT("Referencia Z de sondagem");
  LSTR MSG_PROBE_WIZARD_MOVING            = _UxGT("Movendo para a posicao de sondagem");

  LSTR MSG_XATC                           = _UxGT("X-Twist Wizard");
  LSTR MSG_XATC_DONE                      = _UxGT("X-Twist Wizard Done!");
  LSTR MSG_XATC_UPDATE_Z_OFFSET           = _UxGT("Atualize o deslocamento Z da sonda para ");

  LSTR MSG_SOUND                          = _UxGT("Som");

  LSTR MSG_TOP_LEFT                       = _UxGT("Superior esquerdo");
  LSTR MSG_BOTTOM_LEFT                    = _UxGT("Inferior esquerdo");
  LSTR MSG_TOP_RIGHT                      = _UxGT("Superior Direito");
  LSTR MSG_BOTTOM_RIGHT                   = _UxGT("Inferior Direito");
  LSTR MSG_CALIBRATION_COMPLETED          = _UxGT("Calibracao completa");
  LSTR MSG_CALIBRATION_FAILED             = _UxGT("Calibracao falhou");

  LSTR MSG_DRIVER_BACKWARD                = _UxGT(" driver backward");

  LSTR MSG_SD_CARD                        = _UxGT("SD Card");
  LSTR MSG_USB_DISK                       = _UxGT("Disco USB");

  LSTR MSG_HOST_SHUTDOWN                  = _UxGT("Desligamento do host");

  // These strings can be the same in all languages
  LSTR MSG_MARLIN                         = _UxGT("Marlin");
  LSTR MSG_SHORT_DAY                      = _UxGT("d"); // One character only
  LSTR MSG_SHORT_HOUR                     = _UxGT("h"); // One character only
  LSTR MSG_SHORT_MINUTE                   = _UxGT("m"); // One character only
  LSTR MSG_PID_P                          = _UxGT("PID-P");
  LSTR MSG_PID_P_E                        = _UxGT("PID-P *");
  LSTR MSG_PID_I                          = _UxGT("PID-I");
  LSTR MSG_PID_I_E                        = _UxGT("PID-I *");
  LSTR MSG_PID_D                          = _UxGT("PID-D");
  LSTR MSG_PID_D_E                        = _UxGT("PID-D *");
  LSTR MSG_PID_C                          = _UxGT("PID-C");
  LSTR MSG_PID_C_E                        = _UxGT("PID-C *");
  LSTR MSG_PID_F                          = _UxGT("PID-F");
  LSTR MSG_PID_F_E                        = _UxGT("PID-F *");
  LSTR MSG_BACKLASH_N                     = _UxGT("@");
}

#if FAN_COUNT == 1
  #define MSG_FIRST_FAN_SPEED       MSG_FAN_SPEED
  #define MSG_EXTRA_FIRST_FAN_SPEED MSG_EXTRA_FAN_SPEED
#else
  #define MSG_FIRST_FAN_SPEED       MSG_FAN_SPEED_N
  #define MSG_EXTRA_FIRST_FAN_SPEED MSG_EXTRA_FAN_SPEED_N
#endif
