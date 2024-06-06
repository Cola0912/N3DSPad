# N3DSPad

このプロジェクトは、ESP32マイコンを使用してNew 3DSのボタン配置をエミュレートするカスタムゲームコントローラーを提供します。BleGamepadライブラリを使用して、Bluetooth経由でデバイスと通信します。

## 特徴

- New 3DSのボタン配置をエミュレート
- ESP32を使用してBluetooth接続
- アナログスティックとD-padをサポート

## 必要条件

- ESP32-WROOM-32E
- Arduino IDE
- BleGamepadライブラリ

## インストール

1. リポジトリをクローンします：
    ```sh
    git clone https://github.com/yourusername/N3DSPad.git
    ```
2. Arduino IDEでプロジェクトを開きます。
3. 必要なライブラリをインストールします：
    - BleGamepad
4. コードをESP32ボードにアップロードします。

## 使用方法

- ESP32をBluetooth経由でコンピュータに接続します。
- ゲームコントローラーとして使用します。

## ライセンス

このプロジェクトはBSD 2-Clause Licenseの下でライセンスされています。詳細は[LICENSE](LICENSE)ファイルを参照してください。

## 謝辞

- このプロジェクトでは[BleGamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad)ライブラリを使用しています。
